#include<stdio.h>
#include <stdlib.h>
#include<glut.h>
int sizef = 0, w = 640, h = 480;
void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(250 - sizef, 250 - sizef);
	glVertex2f(250 - sizef, 350 + sizef);
	glVertex2f(350 + sizef, 350 + sizef);
	glVertex2f(350 + sizef, 250 - sizef);
	glEnd();
	glFlush();
}

void Keyboard(unsigned char key, int x, int y) {
	if (key == 'i')
		sizef += 5;
	else if (key == 'd')
		sizef -= 5;
	else if (key == 'r')
		sizef = 0;
	else if (key == 'q')
		exit(0);
	glutPostRedisplay();
}

void main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("Keyboard");
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
}
