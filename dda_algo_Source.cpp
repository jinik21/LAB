#include <GL/glut.h>
#include<iostream>
using namespace std;

void drawLine(int x0, int y0, int x1, int y1) 
{
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = x1 - x0;
	dy = y1 - y0;
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	Xin = dx / step;
	Yin = dy / step;
	x = x0;
	y = y0;
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0); //for black color
	glVertex2i(x, y);
	glEnd();

	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;

		glBegin(GL_POINTS);
		glColor3f(0, 0, 0);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}

void init(void) 
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //for white color window
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(20, 30, 100, 150);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("DDA Line Drawing!");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
