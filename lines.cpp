#include<glut.h>
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void lineSegment() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0xcc10);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 45);
	glEnd();
	glFlush();
}

void main() {
	//glutInit();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("FirstOpenglProgram");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
