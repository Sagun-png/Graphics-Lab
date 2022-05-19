#include<stdio.h>
#include <stdlib.h>
#include<glut.h>
int side = 40, w = 640, h = 480;
void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void mouse(int b, int s, int x, int y) {
	float t;
	y = h - y;
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN) {
		t = side / 2.0;
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x + t, y + t);
		glVertex2f(x + t, y - t);
		glVertex2f(x - t, y - t);
		glVertex2f(x - t, y + t);
		glEnd();
		glFlush();
	}
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN) {
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("MouseEvent");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
