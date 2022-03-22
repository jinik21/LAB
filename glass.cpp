#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void initScreen() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void plot_point(int x, int y, int xcenter, int ycenter)
{
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(xcenter + x, ycenter + y);
	glVertex2i(xcenter + x, ycenter - y);
	glVertex2i(xcenter - x, ycenter - y);
	glVertex2i(xcenter - x, ycenter + y);
	glEnd();
}
void ellipse(int rx, int ry, int xc, int yc)
{
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;
	d1 = pow(ry, 2) - pow(rx, 2) * ry + 0.25 * pow(rx, 2);
	dx = 2 * pow(ry, 2) * x;
	dy = 2 * pow(rx, 2) * y;

	while (dx <= dy)
	{
		plot_point(x, y, xc, yc);
		x++;
		if (d1 < 0)
		{
			dx = dx + 2 * pow(ry, 2);
			d1 = d1 + 2 * (ry * ry) * x + (ry * ry);
		}
		else
		{
			y--;
			dx = dx + 2 * pow(ry, 2);
			dy = dy - 2 * pow(rx, 2);
			d1 = d1 + 2 * (ry * ry) * x + (ry * ry) - 2 * y * rx * rx;
		}
	}

	d2 = (ry * ry) * pow((x + 0.5), 2) + (rx * rx) * pow((y - 1), 2) - pow(rx, 2) * pow(ry, 2);
	while (y > 0)
	{
		plot_point(x, y, xc, yc);
		y--;
		if (d2 > 0)
		{
			dy = dy - 2 * (rx * rx);
			d2 = d2 - 2 * y * rx * rx + (rx * rx);
		}
		else
		{
			x++;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			d2 = d2 + 2 * x * ry * ry - 2 * y * rx * rx + (rx * rx);
		}
	}

}

void line(int x1, int y1, int x2, int y2) {
	float dx = x2 - x1, dy = y2 - y1;
	float m = dy / dx;
	float steps, xInc, yInc;

	if (abs(dx) >= abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}

	xInc = dx / steps;
	yInc = dy / steps;

	float y = y1;
	float x = x1;

	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	while (steps--)
	{
		glVertex2f(x, y);
		x += xInc;
		y += yInc;
	}
	glEnd();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	ellipse(50, 20, 250, 200);
	line(200, 200, 220, 100);
	line(280, 100, 300, 200);
	ellipse(30, 10, 250, 100);
	glFlush();
}



int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Glass");
	initScreen();
	glutDisplayFunc(display);
	glutMainLoop();
	return 1;
}
