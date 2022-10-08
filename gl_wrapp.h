#ifndef GL_WRAPP
#define GL_WRAPP

#include "stdlib.h"
#include "assert.h"
#include "malloc.h"

#include <GL/glut.h>

#define GREEN 0.0, 1.0, 0.0
#define BLACK 0.0, 0.0, 0.0
#define FPS 30

//
typedef GLfloat color_arr[3];
typedef GLfloat* c_arr;
//

enum WindowParams {
    WINDOW_WIDTH = 600,
    WINDOW_HEIGTH = 600
};

enum AppParams {
    APP_WIDTH = 600,
    APP_HEIGHT = 600
};

enum VertexData {
    LEFT_OR_BOTTOM = 0,
    RIGHT_OR_TOP = 1
};
//

/**
 * @brief
 *
 * @param[in] argc
 * @param[in] argv
 */

/**
 * @brief 
 * 
 */
void put_pixel(const GLint x, const GLint y);
void gl_init(int argc, char **argv);

extern void display();
extern void update();

#endif // GL_WRAPP