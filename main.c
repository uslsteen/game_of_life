#include "game_life.h"

field_t main_field, tmp_field;

int main(int argc, char **argv) {
  field_init(&main_field);
  field_init(&tmp_field);

  gl_init(argc, argv);

  field_delete(&main_field);
  field_delete(&tmp_field);

  return 0;
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glBegin(GL_QUADS);
  draw_field(&main_field);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void update() {
  make_next_gen(&main_field, &tmp_field);
  swap(&main_field, &tmp_field);
  //
  glutPostRedisplay();
  glutTimerFunc(1000 / FPS, update, 0);
}