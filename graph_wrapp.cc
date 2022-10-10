#include "graph_wrapp.hh"

namespace graph_impl {

//! NOTE: imagine here SfmlImpl class realziation
static sf::RenderWindow window;
static sf::Image buffer;
static sf::Texture texture;
static sf::Sprite buffer_sprite(texture);
//
static sf::Clock clock;
//
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 */
void graph_init() {
  uint32_t h = AppParams::HEIGHT, w = AppParams::WIDTH;
  //
  window.create(sf::VideoMode(w, h), "Game of Life");
  window.setPosition({0, 0});
  buffer.create(w, h, sf::Color(0, 0, 0));
  //
  //! NOTE: maybe it not useful
  window.setVerticalSyncEnabled(true);
}

void window_clear(uint8_t r, uint8_t g, uint8_t b) {
  window.clear(sf::Color{r, g, b});
}

void flush() {
  window.display();
}

void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
  if (g == 255)
    std::cout << "setting green\n";
  else if (r == 0 and g == 0 and b == 0)
    std::cout << "setting black\n";
  //
  buffer.setPixel(x, y, sf::Color(r, g, b));
  texture.update(buffer);
  window.draw(buffer_sprite);
}

bool is_window_open() { return window.isOpen(); }

} // namespace graph_impl
