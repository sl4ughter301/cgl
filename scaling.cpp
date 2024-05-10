#include <GL/glut.h>

GLfloat vertices[][2] = {
    { -1.0, 1.0 },
    { -1.0, 0.857 },
    { -0.857, 0.857 },
    { -0.857, 1.0 }
};

void drawObject() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2fv(vertices[0]);
    glVertex2fv(vertices[1]);
    glVertex2fv(vertices[2]);
    glVertex2fv(vertices[3]);
    glEnd();
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply scaling transformation
    glScalef(2.0, 2.0, 1.0); // Scale by 2 along X and Y axes

    drawObject();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480); // Set window size
    glutCreateWindow("2D Scaling Example"); // Create window
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
