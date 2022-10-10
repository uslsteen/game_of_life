#ifndef GAME_LIFE
#define GAME_LIFE

#include "graph_wrapp.hh"
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

/**
 * @brief field struct ctor and init
 *
 * @param[in] surf
 */
void field_init(field_t *surf);

int get_neighbours_num(field_t *surf, cell_t cell);

void set_cell(field_t *surf, cell_t cell, enum State state);
int get_cell(field_t *surf, cell_t cell);

void make_next_gen(field_t *surf1, field_t *surf2);
void draw_field(field_t *surf);
void swap(field_t *field1, field_t *field2);

#endif //! GAME_LIFE