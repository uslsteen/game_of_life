#include "game_life.h"

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