#include<stdio.h>
#include<glut.h>
#include<math.h>
int theta = 0;
float x, y, r = 50;

void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void idle() {
	theta += 6;
	if (theta >= 360)
		theta = 0;
	for (unsigned long int i = 0; i <= 5000000; i++);
	glutPostRedisplay();

}

void disp() {
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 1);
	x = r * sin(theta*3.142 / 180);
	y = r * sin(theta *3.142 / 180);

	glBegin(GL_POLYGON);
	glVertex2f(-1 * y, x);
	glVertex2f(-1 * y, x);
	glVertex2f(-1 * x, -1 * y);
	glVertex2f(y, -1 * x);
	glEnd();
	glutSwapBuffers();


}void mouse(int b, int s, int x, int y)
{
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
		glutIdleFunc(idle);
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
		glutIdleFunc(NULL);
}

void main() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Idle");
	init();

	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	glutMainLoop();
}

