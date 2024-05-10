#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

float x_1, y_1, x_2, y_2;

void mouse(int button, int state, int mousex, int mousey) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        x_2 = mousex;
        y_2 = 640 - mousey;
    }
}

void Line() {
    float dy = y_2 - y_1;
    float dx = x_2 - x_1;
    float length = max(abs(dx), abs(dy));

    float xin = dx / length;
    float yin = dy / length;

    float x = x_1 + 0.5 * (xin > 0 ? 1 : -1);
    float y = y_1 + 0.5 * (yin > 0 ? 1 : -1);

    glBegin(GL_POINTS);
    for (int i = 0; i <= length; ++i) {
        glVertex2i(x, y);
        x += xin;
        y += yin;
    }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0, 1.0, 0.0);
    gluOrtho2D(0, 640, 0, 640);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    cout << "Enter x1, y1 point: ";
    cin >> x_1 >> y_1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("DDA LINE DRAWING TECHNIQUE");
    init();
    glutMouseFunc(mouse);
    glutDisplayFunc(Line);
    glutMainLoop();

    return 0;
}

