#include<GL\glut.h>
#include<iostream>

GLfloat v[4][2];
GLint  obj[5];
int static count=0;
int mode = 1;

enum draw_mode {
	line = 1,
	rectangle,
	polygon,
	circle
}md;


bool handle=false;
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
	if (button == GLUT_LEFT_BUTTON && state==GLUT_UP) {
		
		//ver_handle *a;
		//a = new ver_handle;
		v[count][0] = x;
		v[count][1] = y;
		//v[count+1][0] = x;
		//v[count+1][1] = y;
		handle = true;
		std::cout << "Mouse clicked";
		count++;
		
	}
}

void menuhandler(int a) {
	mode=a;
}

void menufunc() {
	glutCreateMenu(menuhandler);
	glutAddMenuEntry("LINE", md=line);
	glutAddMenuEntry("RECTANGLE", md=rectangle);
	glutAddMenuEntry("POLYGON", md=polygon);
	glutAddMenuEntry("CIRCLE", md=circle);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init() {
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 640, 0, 480);

	glFlush();
}

void draw_ver() {
	int i;
	for (i = 0; i < count; i++) {
		//ver_handle v;
		//v.cross();

		glPointSize(15);
		glBegin(GL_POINTS);
		glColor3f(0, 0, 1);
		glVertex2f(v[i][0], 480 - v[i][1]);
		glEnd();

	}

}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (handle == true) {
		int i;
		std::cout << "entered render";
		std::cout << md;
		if (md == 1) {
			std::cout << "entered line";
			draw_ver();
			i = 0;
			int temp;
			temp = count - (count % 2);

			while (i < temp) {

				glBegin(GL_LINES);
				std::cout << "came to line";
				glColor3f(0, 0, 0);
				glVertex2f(v[i][0], 480 - v[i][1]);
				glVertex2f(v[i + 1][0], 480 - v[i + 1][1]);
				glEnd();
				i += 2;
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
