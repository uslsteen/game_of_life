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

enum State { DEAD = 0, ALIVE = 1, NONE };

//
void field_init(field_t *surf) {
  //
  surf->width = WIDTH;
  surf->heigth = HEIGHT;

  for (size_t x = 0; x < surf->width; ++x)
    for (size_t y = 0; y < surf->heigth; ++y) {
      double radius = (double)rand() / RAND_MAX;
      surf->field[y][x] = radius < EPS;
    }
}

//
int get_cell(field_t *surf, cell_t cell) {

  int x = (cell.x + surf->width) % surf->width,
      y = (cell.y + surf->heigth) % surf->heigth;
  return surf->field[y][x];
}

//
void set_cell(field_t *surf, cell_t cell, enum State state) {
  surf->field[cell.y][cell.x] = state;
}

//
int get_neighbours_num(field_t *surf, cell_t cell) {
  int num = 0;
  for (int id_x = -1; id_x <= 1; ++id_x) {
    for (int id_y = -1; id_y <= 1; ++id_y) {
      cell_t other_cell = {id_x + cell.x, id_y + cell.y};
      if ((id_x == 0) && (id_y == 0))
        continue;
      else
        num += get_cell(surf, other_cell);
    }
  }
  return num;
}

//
void make_next_gen(field_t *surf1, field_t *surf2) {
  //
  for (size_t y = 0; y < surf1->heigth; ++y) {
    for (size_t x = 0; x < surf1->width; ++x) {
      //
      cell_t cell = {x, y};
      enum State state = NONE;
      int neighbrs_num = get_neighbours_num(surf1, cell);

      if (get_cell(surf1, cell)) {
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
      set_cell(surf2, cell, state);
    }
  }
}
//

void draw_field(field_t *surf) {
  //
  for (size_t x = 0; x < surf->width; ++x) {
    for (size_t y = 0; y < surf->heigth; ++y) {
      cell_t cell = {x, y};

      int cur_cell = get_cell(surf, cell);
      /*
      if (cur_cell == 1)
        set_pixel(cell.x, cell.y, GREEN);
      else if (cur_cell == 0)
        set_pixel(cell.x, cell.y, BLACK);
      */
     
      switch (get_cell(surf, cell)) {
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
 * @param surf1 
 * @param surf2 
 */
void swap(field_t *surf1, field_t *surf2) {
  field_t tmp = *surf1;
  *surf1 = *surf2;
  *surf2 = tmp;
}

field_t main_field, tmp_field;

int main() {
  graph_init();
  field_init(&main_field);
  field_init(&tmp_field);

  while (is_open_window()) {
    window_clear(BLACK);
    //
    make_next_gen(&main_field, &tmp_field);
    draw_field(&main_field);
    swap(&main_field, &tmp_field);
    //
    flush();
  }

  return 0;
}