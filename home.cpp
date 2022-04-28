#include<glut.h>
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100, 100, -100, 100);
}

void lineSegment() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	// Main Line
	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 10);
	glVertex2i(40, 10);
	glVertex2i(70, 10);
	glVertex2i(70, 40);
	glVertex2i(40, 40);
	glVertex2i(10, 40);
	glEnd();
	// Upper part
	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 40);
	glVertex2i(30, 60);
	glVertex2i(60, 60);
	glVertex2i(70, 40);
	glVertex2i(40, 40);
	glEnd();
	// Diagonal 
	glBegin(GL_LINE_STRIP);
	glVertex2i(30, 60);
	glVertex2i(40, 40);
	glVertex2i(40, 10);
	glEnd();
	// Gate
	glBegin(GL_LINE_LOOP);
	glVertex2i(20, 10);
	glVertex2i(30, 10);
	glVertex2i(30, 20);
	glVertex2i(20, 20);
	glEnd();
	// Chimney
	glBegin(GL_LINE_LOOP);
	glVertex2i(40, 60);
	glVertex2i(40, 65);
	glVertex2i(45, 65);
	glVertex2i(45, 60);
	glEnd();
	// Window
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 25);
	glVertex2i(50, 35);
	glVertex2i(60, 35);
	glVertex2i(60, 25);
	glEnd();
	// Window Strips
	glBegin(GL_LINE_STRIP);
	glVertex2i(55, 25);
	glVertex2i(55, 35);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(50, 30);
	glVertex2i(60, 30);
	glEnd();

	glFlush();
}

void main() {
	//glutInit();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("FirstOpenglProgram");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
