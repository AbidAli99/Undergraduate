#include <GL/freeglut.h>
#include <math.h>

#define PI 3.1415926535898

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat r, GLfloat g, GLfloat b) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.5);

    // Rectangle
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0, 10.0);
    glVertex2f(10.0, 10.0);
    glVertex2f(10.0, -10.0);
    glVertex2f(-10.0, -10.0);
    glEnd();

    // Big circle 1st half
    GLint circle_points = 200;
    GLfloat angle;
    glColor3f(0, 0, 0.8);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circle_points; i++) {
        angle = 2 * PI * i / circle_points;
        glVertex2f(cos(angle) / 0.3, sin(angle) / 0.3);
    }
    glEnd();

    // Big circle 2nd half
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = -30; i < (circle_points - 40); i++) {
        angle = PI * i / circle_points;
        glVertex2f(cos(angle) / 0.3, sin(angle) / 0.3);
    }
    glEnd();

    drawFilledCircle(1.27, -1.2, 1.73, 0, 0, 0.8);
    drawFilledCircle(-1.23, 1.2, 1.73, 1, 0, 0);

    glFlush();
}

void init(void) {
    glClearColor(1, 1, 1, 0.0);
    glOrtho(-10, 10, -8, 8, -10, 10);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize FreeGLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(400, 200); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("South Korea National Flag"); // Create window with title
    init(); // Initialize OpenGL settings
    glutDisplayFunc(display); // Set display callback function
    glutMainLoop(); // Enter the main event loop
    return 0;
}
