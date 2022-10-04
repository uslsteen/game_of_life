#ifndef GAME_LIFE
#define GAME_LIFE

#include "gl_wrapp.h"

#define EPS 0.1

typedef struct field_t {
  int **field;
  GLint width;
  GLint heigth;
} field_t;

typedef struct cell_t {
  int x, y;
} cell_t;

enum State { DEAD = 0, ALIVE = 1, NONE };

/**
 * @brief field struct ctor and init
 * 
 * @param[in] surf 
 */
void field_init(field_t *surf);

/**
 * @brief field struct dctor
 * 
 * @param[in] surf 
 */
void field_delete(field_t *surf);

int get_neighbours_num(field_t *surf, cell_t cell);

void set_cell(field_t* surf, cell_t cell, enum State state);
int get_cell(field_t* surf, cell_t cell);

void make_next_gen(field_t* surf1, field_t* surf2);
void draw_field(field_t* surf);
void swap(field_t *field1, field_t *field2);

#endif //! GAME_LIFE