#include <GL/glut.h>
#include<iostream>
using namespace std;

int x4, y4, x5, y5;
void bres(int x1, int y1, int x2, int y2)
{
    int dx, dy, p;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 *(dy)-(dx);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(x1, y1);
    glEnd();
    int x = x1;
    int y = y1;
    while (x < x2)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * (dy);
        }
        else
        {
            y++;
            p = p + 2 * (dy - dx);
        }
        glBegin(GL_POINTS);
        glColor3f(1, 1, 1);
        glVertex2i(x, y);
        glEnd();
    }
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //white color window
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 800);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    bres(x4, y4, x5, y5);
    glFlush();
}

int main(int argc, char* argv[])
{
    cout << "Enter x1 : ";
    cin >> x4;
    cout << "Enter y1 : ";
    cin >> y4;
    cout << "Enter x2 : ";
    cin >> x5;
    cout << "Enter y2 : ";
    cin >> y5;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init(); 
    glutDisplayFunc(display);
    glutMainLoop();
}