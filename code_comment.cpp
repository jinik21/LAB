#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //set display-window color to white
	//glClearColor(0.0, 0.0, 0.0, 0.0); //set display-window color to black
	glMatrixMode(GL_PROJECTION); //set projection parameters.
	gluOrtho2D(0.0, 200.0, 0.0, 150.0); //Orthographic Projection of 3D object to 2D image
}
void DDALineDrawing(void)
{
	float x1 = 10;
	float y1 = 20;
	float x2 = 70;
	float y2 = 40;
	float dx = x2 - x1;
	float dy = y2 - y1;
	float step = 0;
	if (fabs(dx) > fabs(dy))
		step = dx;
	else
		step = dy;
	float xincr = dx / step;
	float yincr = dy / step;
	//cout << xincr;
	//cout << yincr;
	float x0 = x1;
	float y0 = y1;
	glClear(GL_COLOR_BUFFER_BIT); //clear display window
	glColor3f(0.0, 0.0, 0.0); //set point color to black
	//3f signifies that take 3 float values as arguments - R, G, B
	//set point size, color etc before glBegin
	glBegin(GL_POINTS);	//starts drawing
	glVertex2f(x0, y0);
	int xplot=0, yplot=0;
	while (xplot != x2 && yplot != y2)
	{
		x0 += xincr;
		y0 += yincr;
		xplot = round(x0);
		yplot = round(y0);
		glVertex2f(xplot, yplot); //set point location
	}
	glEnd();
	glFlush(); //process all OpenGL routines as quickly as possible
}
void BrassenhamAlgorithm(void)
{
	int x1 = 10;
	int y1 = 20;
	int x2 = 70;
	int y2 = 100;
	float dx = x2 - x1;
	float dy = y2 - y1;
	float m = fabs(dy / dx);
	glClear(GL_COLOR_BUFFER_BIT); //clear display window
	glColor3f(0.0, 0.0, 0.0); //set point color to black
	//3f signifies that take 3 float values as arguments - R, G, B
	//set point size, color etc before glBegin
	glBegin(GL_POINTS);	//starts drawing
	if (m <= 1)
	{
		int xincr = 1;
		int yincr = 0;
		int p = 2 * dy - dx;
		int x0 = x1;
		int y0 = y1;
		glVertex2i(x0, y0); //set point location
		while (x0 != x2 && y0 != y2)
		{
			
			x0 += xincr;
			if (p < 0)
			{
				yincr = 0;
				p = p + 2 * dy;
			}
			else
			{
				yincr = 1;
				p = p + 2 * dy - 2 * dx;
			}
			y0 += yincr;
			glVertex2i(x0, y0); //set point location
		}
	}
	else if (m > 1)
	{
		int xincr = 0;
		int yincr = 1;
		int p = 2 * dx - dy;
		int x0 = x1;
		int y0 = y1;
		glVertex2i(x0, y0); //set point location
		while (x0 != x2 && y0 != y2)
		{

			y0 += yincr;
			if (p < 0)
			{
				xincr = 0;
				p = p + 2 * dx;
			}
			else
			{
				xincr = 1;
				p = p + 2 * dx - 2 * dy;
			}
			x0 += xincr;
			glVertex2i(x0, y0); //set point location
		}

	}
	glEnd();
	glFlush(); //process all OpenGL routines as quickly as possible
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); //initialize glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Single Frame Buffer, Color Mode- RGB
	//these are also the default arguments for the above function
	glutInitWindowPosition(50, 100); //set top-left display window position
	//bottom left of the window is (0,0)
	glutInitWindowSize(400, 300); //set display window width and height
	glutCreateWindow("Line Segment Window"); //create display window with the specified name
	init();
	glutDisplayFunc(BrassenhamAlgorithm); //send graphics to display window
	glutMainLoop(); //display everything and wait
    return 0;
}