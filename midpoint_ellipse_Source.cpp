#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int xcenter, ycenter, rx, ry;
void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xcenter + x, ycenter + y);
	glVertex2i(xcenter + x, ycenter - y);
	glVertex2i(xcenter - x, ycenter - y);
	glVertex2i(xcenter - x, ycenter + y);
	glEnd();
}
// void plot_point_r2(int x, int y)
// {
// 	glBegin(GL_POINTS);
// 	// glVertex2i(xcenter + x, ycenter + y);
// 	// glVertex2i(xcenter + x, ycenter - y);
// 	// glVertex2i(xcenter - x, ycenter - y);
// 	// glVertex2i(xcenter - x, ycenter + y);
// 	glVertex2i(xcenter - y, ycenter + x);
// 	glVertex2i(xcenter - y, ycenter - x);
// 	glVertex2i(xcenter + y, ycenter + x);
// 	glVertex2i(xcenter + y, ycenter - x);
// 	glEnd();
// }
void ellipse()
{
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;
	d1 = pow(ry, 2) - pow(rx, 2) * ry + 0.25 * pow(rx, 2);
	dx = 2 * pow(ry, 2) * x;
	dy = 2 * pow(rx, 2) * y;
	while (dx <= dy)
	{
		plot_point(x, y);
		x++;
		if (d1 < 0)
		{
			dx = dx + 2 * pow(ry, 2);
			d1 = d1 + 2*(ry * ry)*x + (ry * ry);
		}
		else
		{
			y--;
			dx = dx + 2 * pow(ry, 2);
			dy = dy - 2 * pow(rx, 2);
			d1 = d1 + 2 * (ry * ry) * x + (ry * ry) - 2*y*rx*rx;
		}
	}
	d2 = (ry * ry) * pow((x + 0.5), 2) + (rx * rx) * pow((y - 1), 2) - pow(rx, 2)* pow(ry, 2);
	while (y > 0)
	{
		plot_point(x, y);
		y--;
		if (d2 > 0)
		{
			dy = dy - 2 * (rx * rx);
			d2 = d2 - 2*y*rx*rx + (rx * rx);
		}
		else
		{
			x++;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			d2 = d2 + 2*x*ry*ry - 2*y*rx*rx + (rx * rx);
		}
	}
}
void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 400);
	ellipse();
	glFlush();
}
int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n" << endl;
	cout << "X-coordinate : ";
	cin >> xcenter;
	cout << "Y-coordinate : ";
	cin >> ycenter;
	cout << "Enter major radius : ";
	cin >> rx; 
	cout << "Enter minor radius : ";
	cin >> ry; 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 200);
	glutInitWindowSize(800, 400);
	glutCreateWindow("Mid-point Ellipse");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
