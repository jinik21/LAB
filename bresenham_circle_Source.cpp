#include <GL/glut.h>
#include <iostream>
using namespace std;

int xcenter, ycenter, r;
void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xcenter + x, ycenter + y);
	glVertex2i(xcenter + x, ycenter - y);
	glVertex2i(xcenter + y, ycenter + x);
	glVertex2i(xcenter + y, ycenter - x);
	glVertex2i(xcenter - x, ycenter - y);
	glVertex2i(xcenter - y, ycenter - x);
	glVertex2i(xcenter - x, ycenter + y);
	glVertex2i(xcenter - y, ycenter + x);
	glEnd();
}
void bresenham_circle()
{
	int x = 0, y = r;
	int p = 3 - 2 * r;
	plot_point(x, y);
	while (y >= x)
	{
		x++;
		if (p < 0)
			p = p + 4 * x + 6;
		else
		{
			y--;
			p = p + 4 * (x - y) + 10;
		}
		plot_point(x, y);
	}
}
void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 400);
	bresenham_circle();

	glFlush();
}
int main(int argc, char *argv[])
{
	cout << "Enter the coordinates of the center:\n"
		 << endl;
	cout << "X-coordinate : ";
	cin >> xcenter;
	cout << "Y-coordinate : ";
	cin >> ycenter;
	cout << "Enter radius : ";
	cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Bresenham-Circle");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}