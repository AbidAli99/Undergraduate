#define FREEGLUT_STATIC
#include <GL\freeglut.h>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>

void init(void);
void drawFlag(void);
void drawRedTriangle(void);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Flag of Palestine");

    init();
    glutDisplayFunc(drawFlag);
    glutMainLoop();

    return 0;
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(0, 600, 0, 400);        // Set the coordinate system
}

void drawFlag(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the black stripe
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 266);
    glVertex2i(600, 266);
    glVertex2i(600, 400);
    glVertex2i(0, 400);
    glEnd();

    // Draw the white stripe
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 133);
    glVertex2i(600, 133);
    glVertex2i(600, 266);
    glVertex2i(0, 266);
    glEnd();

    // Draw the green stripe
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(600, 0);
    glVertex2i(600, 133);
    glVertex2i(0, 133);
    glEnd();

    // Draw the red triangle
    drawRedTriangle();

    glFlush(); // Ensure all drawing commands are executed
}

void drawRedTriangle(void)
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 400);
    glVertex2i(200, 200);
    glEnd();
}
