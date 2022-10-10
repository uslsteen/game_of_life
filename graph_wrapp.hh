#ifndef GL_WRAPP
#define GL_WRAPP

#include <iostream>
#include <SFML/Graphics.hpp>

#define GREEN 0, 255, 0
#define BLACK 0, 0, 0

namespace graph_impl {
/**
 * @brief 
 * 
 */
enum AppParams { WIDTH = 800, HEIGHT = 800 };

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 */
void graph_init();

//! NOTE: sf::Color color;
/**
 * @brief 
 * 
 * @param r 
 * @param g 
 * @param b 
 */
void window_clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool is_window_open();

/**
 * @brief Set the pixel object
 * 
 * @param x 
 * @param y 
 * @param r 
 * @param g 
 * @param b 
 */
void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief 
 * 
 */
void flush();

} // namespace graph_impl
#endif // GL_WRAPP