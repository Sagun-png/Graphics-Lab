#include<glut.h>
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void points() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(180, 15);
	glVertex2i(10, 45);
	glEnd();
	glFlush();
}

void main() {
	//glutInit();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("SecondOpenglProgram");
	init();
	glutDisplayFunc(points);
	glutMainLoop();
}
