#include "game_life.hh"

field_t main_field, tmp_field;

int main() {

  graph_impl::graph_init();
  field_init(&main_field);
  field_init(&tmp_field);

  while (graph_impl::is_window_open()) {
    graph_impl::window_clear();
    //
    make_next_gen(&main_field, &tmp_field);
    draw_field(&main_field);
    swap(&main_field, &tmp_field);
    //
    graph_impl::flush();
  }

  return 0;
}