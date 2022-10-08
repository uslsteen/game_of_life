#include "gl_wrapp.h"

GLint window_width = WINDOW_WIDTH;
GLint window_height = WINDOW_HEIGTH;

GLfloat LEFT = LEFT_OR_BOTTOM,
        BOTTOM = LEFT_OR_BOTTOM,
        RIGHT = RIGHT_OR_TOP,
        TOP = RIGHT_OR_TOP;

void put_pixel(const GLint x, const GLint y) {
    GLfloat x_size = (RIGHT - LEFT) / APP_WIDTH,
            y_size = (TOP - BOTTOM) / APP_HEIGHT;

    glVertex2f(x * x_size + LEFT, y * y_size + BOTTOM);
    glVertex2f((x + 1) * x_size + LEFT, y * y_size + BOTTOM);
    glVertex2f((x + 1) * x_size + LEFT, (y + 1) * y_size + BOTTOM);
    glVertex2f(x * x_size + LEFT, (y + 1) * y_size + BOTTOM);
}

void reshape(int w, int h) {
	window_width = w;
	window_height = h;

	glViewport(0, 0, window_width, window_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(LEFT, RIGHT, BOTTOM, TOP);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void gl_init(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(window_width, window_height);
  glutCreateWindow("Conway's game life");
  //
  glClearColor(1, 1, 1, 1);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  update();
  //
  glutMainLoop();
}