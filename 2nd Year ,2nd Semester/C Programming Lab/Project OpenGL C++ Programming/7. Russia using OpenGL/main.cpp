#include <GL/glut.h>

void display()
{
    glClearColor(0, 0, 0, 1); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    glRectf(1, 11, 30, 22);

    glColor3f(1, 0, 0);
    glRectf(1, 1, 30, 8);

    glColor3f(0, 0, 1);
    glRectf(1, 8, 30, 15);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Drawing rectangles");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 31, 0, 23);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

