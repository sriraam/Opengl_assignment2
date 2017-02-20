#include<GL\glut.h>
#include<iostream>

GLfloat v[4][2];
GLint  obj[5];
int static count;
bool handle=false;
class ver_handle {
public:
	GLfloat ver[1];
	void cross() {
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(v[0][0] + 15, 480 - (v[0][1] + 15));
		std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(v[0][0] - 15, 480 - (v[0][1] - 15));
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(v[0][0] - 15, 480 - (v[0][1] + 15));
		std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(v[0][0] + 15, 480 - (v[0][1] - 15));
		glEnd();
	}


};



void click_handle(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		v[0][0] = x;
		v[0][1] = y;
		handle = true;
		count++;
		ver_handle *a = new ver_handle();
		
	}
}

void init() {
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 640, 0, 480);

	glFlush();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (handle == true) {
		int i;
		for (i = 0; i < count; i++) {
			ver_handle v;
			v.cross();
			//ver_handle::cross();
		}

		/*std::cout << "line called";
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
	//	glVertex2f(15, 15);
		glVertex2f(v[0][0] + 15, 480-(v[0][1] + 15));
		std::cout << v[0][0] <<" "<< v[0][1];
	//	glVertex2f(0, 0);
		glVertex2f(v[0][0] - 15, 480 - (v[0][1] - 15));
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
	glutDisplayFunc(render);
    glutMouseFunc(click_handle);
	glutMainLoop();
	return 0;
}
