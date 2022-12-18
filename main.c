#include "graph_wrapp/graph_wrapp.hh"
//
#include <stdlib.h>

int WIDTH = 800;
int HEIGHT = 800;

uint8_t main_field[800 * 800], tmp_field[800 * 800];

int DEAD = 0;
int ALIVE = 1;
int NONE = 2;

//
void field_init() {
  //
  for (size_t x = 0; x < WIDTH * HEIGHT; ++x)
      main_field[x] = get_random_val();
}

//
int get_cell(int x, int y) {

  int res_x = (x + WIDTH) % WIDTH;
  int res_y = (y + HEIGHT) % HEIGHT;
  return main_field[res_y * WIDTH + res_x];
}

//
int get_neighbours_num(int x, int y) {
  int num = 0;

  num = get_cell(x - 1, y - 1) + get_cell(x, y - 1) + get_cell(x + 1, y - 1) +
        get_cell(x + 1, y) + get_cell(x + 1, y + 1) + get_cell(x, y + 1) +
        get_cell(x - 1, y + 1) + get_cell(x - 1, y);
  //
  return num;
}

//
void make_next_gen() {
  //
  for (size_t y = 0; y < HEIGHT; ++y) {
    for (size_t x = 0; x < WIDTH; ++x) {
      //
      int state = NONE;
      int neighbrs_num = get_neighbours_num(x, y);
      int cur_cell = get_cell(x, y);
      //
      if (cur_cell == 1) {
        if (neighbrs_num == 2 || neighbrs_num == 3)
          state = ALIVE;
        else
          state = DEAD;
      }
      if (cur_cell == 0) {
        if (neighbrs_num == 3)
          state = ALIVE;
        else
          state = DEAD;
      }
      tmp_field[y * WIDTH + x] = state;
    }
  }
}
//

void draw_field() {
  //
  for (size_t x = 0; x < WIDTH; ++x) {
    for (size_t y = 0; y < HEIGHT; ++y) {
      int cur_cell = get_cell(x, y);

      if (cur_cell == 1)
        set_pixel(x, y, 0, 255, 0);
      if (cur_cell == 0)
        set_pixel(x, y, 0, 0, 0);
    }
  }
}

/**
 * @brief
 *
 * @param main_field
 * @param tmp_field
 */
void swap() {
  //
  for (int x = 0; x < WIDTH * HEIGHT; ++x)
    main_field[x] = tmp_field[x];
}

//
int main() {
  graph_init();
  field_init();

  while (is_open_window()) {
    window_clear(0, 0, 0);
    //
    make_next_gen();
    draw_field();
    swap();
    //
    flush();
  }

  return 0;
}