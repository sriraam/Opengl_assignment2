#include<GL\glut.h>
#include<iostream>
#include<vector>


GLfloat v[4][2];
GLint  obj[5];
int static count=0;
int mode = 1;
int count_ver=0;
int j = 0;
bool handle=false;

std::vector<GLfloat> x_vec;
std::vector<GLfloat> y_vec;
std::vector<int> current_mode;


//x_vec.reserve(10);

enum draw_mode {
	line = 1,
	rectangle,
	polygon,
	circle
}md;

void menuhandler(int a) {
	mode = a;
	current_mode.push_back(mode);
}

void menufunc() {
	glutCreateMenu(menuhandler);
	glutAddMenuEntry("LINE", md = line);
	glutAddMenuEntry("RECTANGLE", md = rectangle);
	glutAddMenuEntry("POLYGON", md = polygon);
	glutAddMenuEntry("CIRCLE", md = circle);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/*
class ver_handle {
public:
	GLfloat ver[1];
	void cross() {
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(ver[0] + 15, 480 - (ver[1] + 15));
		//std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(ver[0] - 15, 480 - (ver[1] - 15));
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(ver[0] - 15, 480 - (ver[1] + 15));
		//std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(ver[0] + 15, 480 - (ver[1] - 15));
		glEnd();
	}


};*/



void click_handle(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) {

		
		if (current_mode.size()==0) {
			std::cout << "size =0";
			current_mode.push_back(1);
		}
		//For vertex point generation
		v[count][0] = x;
		v[count][1] = y;

		//To keep track of ver
		x_vec.push_back(x);
		y_vec.push_back(y);

		if (current_mode[current_mode.size()-1]==3) {
			std::cout <<"countver"<< count_ver;
			count_ver++;
		}
		else {
			count_ver = 0;
		}
		
		
		handle = true;
		//std::cout << "Mouse clicked";
		count++;
		
	}
}

void init() {
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 640, 0, 480);
	x_vec.reserve(20);
	y_vec.reserve(20);
	current_mode.reserve(10);
	glFlush();
}

void draw_line(int i_dp,int temp_dp) {
	int i = i_dp;
	int temp = temp_dp;
	if (i < temp) {
		std::cout << "in line\n";
		glBegin(GL_LINES);
		//std::cout << "came to line";
		glColor3f(1, 0, 0);
		//	glVertex2f(v[i][0], 480 - v[i][1]);
		//  glVertex2f(v[i + 1][0], 480 - v[i + 1][1]);
		glVertex2f(x_vec[i], 480 - y_vec[i]);
		glVertex2f(x_vec[i + 1], 480 - y_vec[i + 1]);
		glEnd();
		
	}
}
void draw_rect(int i_dp, int temp_dp) {
	int i = i_dp;
	int temp = temp_dp;
	if (i < temp) {
		glBegin(GL_LINE_LOOP);
		std::cout << "in rec\n";
		glColor3f(0, 1, 0);
		glVertex2f(x_vec[i], 480 - y_vec[i]);
		glVertex2f(x_vec[i], 480 - y_vec[i + 1]);
		glVertex2f(x_vec[i + 1], 480 - y_vec[i + 1]);
		glVertex2f(x_vec[i + 1], 480 - y_vec[i]);
		glEnd();

	}
}

void draw_polygon(int i_dp,int temp_dp) {
	int i = i_dp;
	int temp = temp_dp;
	glBegin(GL_LINE_LOOP);
	std::cout << "entered polygon\n";
	glColor3f(0, 0, 0);
	for (i; i < count_ver;i++) {
		glVertex2f(x_vec[i],480-y_vec[i]);
		//glVertex2f(x_vec[i+1], 480 - y_vec[i+1]);
	}
	glEnd();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (handle == true) {
		int i;
		//int j;
		for (i = 0; i < count; i++) {
			//ver_handle v;
			//v.cross();

			glPointSize(15);
			glBegin(GL_POINTS);
			glColor3f(0, 0, 1);
			//glVertex2f(v[i][0], 480 - v[i][1]);
			glVertex2f(x_vec[i],480-y_vec[i]);
			glEnd();

		}
		
				i = 0;
				
				int temp;
				temp = count - (count % 2);

				std::cout << "\n";
				for (int j = 0; j < current_mode.size(); j++) {

					if (current_mode[j] == 1) {
					
						std::cout << "j :" << j<<" val is"<< current_mode[j];
						std::cout << "\nEntered line\n";
						draw_line(i,temp);
						i += 2;
					}
					else if (current_mode[j] == 2) {
						
						std::cout << "j :" << j << " val is" << current_mode[j];
						std::cout << "\nEntered rect\n";
						draw_rect(i, temp);
						i += 2;
					}
					else if (current_mode[j]==3) {
						draw_polygon(i, temp);
						i += count_ver;
						//count_ver = 0;
					}
				}
				
				/*
						std::cout << "line called";
						glBegin(GL_LINES);
						glColor3f(1, 0, 0);
					//	glVertex2f(15, 15);
						glVertex2f(v[0][0] , v[0][1]);
						std::cout << v[0][0] <<" "<< v[0][1];
					//	glVertex2f(0, 0);
						glVertex2f(v[0][0] , v[0][1]);
						glEnd();

						glBegin(GL_LINES);
						glColor3f(1, 0, 0);
						//	glVertex2f(15, 15);
						glVertex2f(v[0][0] - 15, 480 - (v[0][1] + 15));
						std::cout << v[0][0] << " " << v[0][1];
						//	glVertex2f(0, 0);
						glVertex2f(v[0][0] + 15, 480 - (v[0][1] - 15));
						glEnd();
						handle = false;
					*/

			
		}
	
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("DRAW PRI");
	init();
	menufunc();
	glutDisplayFunc(render);
    glutMouseFunc(click_handle);
	glutMainLoop();
	return 0;
}
