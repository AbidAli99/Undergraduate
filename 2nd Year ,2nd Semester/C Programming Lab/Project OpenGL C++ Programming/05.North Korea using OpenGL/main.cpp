#include <GL/glut.h>
#include <math.h>

void idle() {
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);

    // Draw the flag of North Korea
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 8.0);
    glVertex2f(10.0, 8.0);
    glVertex2f(10.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 6.0);
    glVertex2f(0.0, 8.0);
    glVertex2f(10.0, 8.0);
    glVertex2f(10.0, 6.0);
    glEnd();

    glLineWidth(3.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 9.0);
    glVertex2f(0.0, -10.0);
    glVertex2f(-0.5, -10.0);
    glVertex2f(-0.5, 9.0);
    glEnd();

    glLineWidth(3.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float d = i * 3.142 / 180;
        glVertex2f(3.0 + 1.0 * cos(d), 4.0 + 1.0 * sin(d));
    }
    glEnd();

    glLineWidth(3.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float d = i * 3.142 / 180;
        glVertex2f(-0.25 + 1.0 * cos(d), -10.0 + 1.0 * sin(d));
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 6.0);
    glVertex2f(10.0, 6.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(10.0, 2.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(10.0, 2.0);
    glVertex2f(10.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.5, 4.5);
    glVertex2f(3.0, 5.0);
    glVertex2f(3.5, 4.5);
    glVertex2f(3.9, 4.5);
    glVertex2f(3.5, 3.9);
    glVertex2f(4.0, 3.0);
    glVertex2f(3.0, 3.5);
    glVertex2f(2.2, 3.0);
    glVertex2f(2.5, 3.9);
    glVertex2f(2.1, 4.5);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.0, 9.0);
    glVertex2f(-0.25, 9.5);
    glVertex2f(-0.5, 9.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("North Korea");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
