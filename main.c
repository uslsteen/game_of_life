#include "graph_wrapp/graph_wrapp.hh"
//
#include <stdlib.h>

#define EPS 0.1

typedef struct cell_t {
  size_t x, y;
} cell_t;

typedef struct field_t {
  uint8_t field[WIDTH][HEIGHT];
  uint32_t width;
  uint32_t heigth;
} field_t;

field_t main_field, tmp_field;

enum State { DEAD = 0, ALIVE = 1, NONE };

//
void field_init() {
  //
  for (size_t x = 0; x < WIDTH; ++x)
    for (size_t y = 0; y < HEIGHT; ++y) {
      double radius = (double)rand() / RAND_MAX;
      main_field.field[y][x] = radius < EPS;
    }
}

//
int get_cell(cell_t cell) {

  int x = (cell.x + WIDTH) % WIDTH, y = (cell.y + HEIGHT) % HEIGHT;
  return main_field.field[y][x];
}

//
void set_cell(cell_t cell, enum State state) {
  tmp_field.field[cell.y][cell.x] = state;
}

//
int get_neighbours_num(cell_t cell) {
  int num = 0;
  for (int id_x = -1; id_x <= 1; ++id_x) {
    for (int id_y = -1; id_y <= 1; ++id_y) {
      cell_t other_cell = {id_x + cell.x, id_y + cell.y};
      if ((id_x == 0) && (id_y == 0))
        continue;
      else
        num += get_cell(other_cell);
    }
  }
  return num;
}

//
void make_next_gen() {
  //
  for (size_t y = 0; y < HEIGHT; ++y) {
    for (size_t x = 0; x < WIDTH; ++x) {
      //
      cell_t cell = {x, y};
      enum State state = NONE;
      int neighbrs_num = get_neighbours_num(cell);

      if (get_cell(cell)) {
        if (neighbrs_num == 2 || neighbrs_num == 3)
          state = ALIVE;
        else
          state = DEAD;
      } else {
        if (neighbrs_num == 3)
          state = ALIVE;
        else
          state = DEAD;
      }
      set_cell(cell, state);
    }
  }
}
//

void draw_field() {
  //
  for (size_t x = 0; x < WIDTH; ++x) {
    for (size_t y = 0; y < HEIGHT; ++y) {
      cell_t cell = {x, y};
      //
      switch (get_cell(cell)) {
      case 1: {
        set_pixel(cell.x, cell.y, GREEN);
        break;
      }
      case 0: {
        set_pixel(cell.x, cell.y, BLACK);
        break;
      }
      default:
        break;
      }
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
  uint8_t tmp = 0;
  //
  for (size_t x = 0; x < WIDTH; ++x) {
    for (size_t y = 0; y < HEIGHT; ++y) {
        tmp = main_field.field[y][x];
        main_field.field[y][x] = tmp_field.field[y][x];
        tmp_field.field[y][x] = tmp;
    }
  }
}

//
int main() {
  graph_init();
  field_init(&main_field);

  while (is_open_window()) {
    window_clear(BLACK);
    //
    make_next_gen();
    draw_field();
    swap();
    //
    flush();
  }

  return 0;
}