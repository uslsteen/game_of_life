#include "graph_wrapp.hh"

#include <SFML/Graphics.hpp>

namespace graph_impl {
//! NOTE: imagine here SfmlImpl class realziation
static sf::RenderWindow window;
static sf::Image buffer;
static sf::Texture texture;
static sf::Sprite sprite;
//
} // namespace graph_impl

#ifdef __cplusplus
extern "C" {
#endif
void graph_init() {
  uint32_t h = AppParams::APP_HEIGHT, w = AppParams::APP_WIDTH;
  //
  graph_impl::window.create(sf::VideoMode(w, h), "Game of Life");
  graph_impl::buffer.create(w, h, sf::Color(BLACK));
  //
  //! NOTE: maybe it not useful
  graph_impl::window.setVerticalSyncEnabled(true);
}

void window_clear(uint8_t r, uint8_t g, uint8_t b) {
  graph_impl::window.clear(sf::Color{r, g, b});
}

void flush() { graph_impl::window.display(); }

bool is_open_window() { return graph_impl::window.isOpen(); }

void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
  sf::RectangleShape pixel{sf::Vector2f(RECT_SIZE)};
  pixel.setFillColor(sf::Color{r, g, b});
  pixel.setPosition(sf::Vector2f(x, y));

  graph_impl::window.draw(pixel);
}

int get_random_val() {
    double radius = (double)rand() / RAND_MAX;
    return radius < EPS;
}
#ifdef __cplusplus
}
#endif
