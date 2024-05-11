#include <GL/freeglut.h>
#include <math.h>

#define PI 3.1415926535898

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(0.5);

    // Black rectangle
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-10.0, -10.0);
    glVertex2f(-10.0, -3.66);
    glVertex2f(10.0, -3.66);
    glVertex2f(10.0, -10.0);
    glEnd();

    // Red rectangle
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-10.0, 10.0);
    glVertex2f(-10.0, 3.66);
    glVertex2f(10.0, 3.66);
    glVertex2f(10.0, 10.0);
    glEnd();

    // Left Star
    glColor3f(0, 0.6, 0);
    glBegin(GL_QUADS);
    glVertex2f(-2.00, 0.5);
    glVertex2f(-2.6, 0.5);
    glVertex2f(-2.6, -0.5);
    glVertex2f(-2.0, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-1.9, 0.5);
    glVertex2f(-2.5, 0.5);
    glVertex2f(-2.2, 1.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-1.1, 0.7);
    glVertex2f(-2.5, 0.5);
    glVertex2f(-3.1, -1.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-3.45, 0.8);
    glVertex2f(-2.00, 0.5);
    glVertex2f(-1.5, -1.2);
    glEnd();

    // Right Star
    glColor3f(0, 0.6, 0);
    glBegin(GL_QUADS);
    glVertex2f(2.00, 0.5);
    glVertex2f(2.6, 0.5);
    glVertex2f(2.6, -0.5);
    glVertex2f(2.0, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(2.0, 0.5);
    glVertex2f(2.6, 0.5);
    glVertex2f(2.3, 1.8);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(3.3, 0.8);
    glVertex2f(2.0, 0.5);
    glVertex2f(1.7, -1.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1.25, 0.7);
    glVertex2f(2.6, 0.5);
    glVertex2f(3.0, -1.0);
    glEnd();

    glFlush();
}

void init(void) {
    glClearColor(1, 1, 1, 0.0);
    glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize FreeGLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(400, 200); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("National Flag of Syria"); // Create window with title
    init(); // Initialize OpenGL settings
    glutDisplayFunc(display); // Set display callback function
    glutMainLoop(); // Enter the main event loop
    return 0;
}

