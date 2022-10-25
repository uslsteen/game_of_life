#ifndef GL_WRAPP
#define GL_WRAPP

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define GREEN 0, 255, 0
#define BLACK 0, 0, 0

#define RECT_SIZE 1.0, 1.0

enum AppParams { WIDTH = 800, HEIGHT = 800 };

#ifdef __cplusplus
extern "C" {
#endif
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
void window_clear(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool is_open_window();
/**
 * @brief
 *
 */
void flush();

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

#ifdef __cplusplus
}
#endif
//
#endif // GL_WRAPP