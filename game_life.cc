#include "game_life.hh"

//
void field_init(field_t *surf) {
  //
  surf->width = graph_impl::AppParams::WIDTH;
  surf->heigth = graph_impl::AppParams::HEIGHT;

  for (size_t x = 0; x < surf->width; ++x)
    for (size_t y = 0; y < surf->heigth; ++y) {
      double radius = (double)rand() / RAND_MAX;
      surf->field[y][x] = radius < EPS;
    }
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
void set_cell(field_t *surf, cell_t cell, enum State state) {
  surf->field[cell.y][cell.x] = state;
}
//
int get_cell(field_t *surf, cell_t cell) {

  int x = (cell.x + surf->width) % surf->width,
      y = (cell.y + surf->heigth) % surf->heigth;
  return surf->field[y][x];
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

      switch (get_cell(surf, cell)) {
      case 1: {
        graph_impl::set_pixel(cell.x, cell.y, GREEN);
        break;
      }
      case 0: {
        graph_impl::set_pixel(cell.x, cell.y, BLACK);
        break;
      }
      default:
        break;
      }
    }
  }
}

//
void swap(field_t *surf1, field_t *surf2) {
  uint8_t tmp = 0;
  //
  for (size_t x = 0; x < surf1->width; ++x) {
    for (size_t y = 0; y < surf1->heigth; ++y) {
      tmp = surf2->field[y][x];
      surf1->field[y][x] = surf2->field[y][x];
      surf2->field[y][x] = tmp;
    }
  }
}
