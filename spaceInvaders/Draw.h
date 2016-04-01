#ifndef __DRAW_H__
#define __DRAW_H__
#include <glut.h>

class Draw{
public:
    int i;
    void line2d(int x, int y, int xf, int yf, GLfloat l);
    void point2d(int x, int y, GLfloat l);
    void ship2d(int** shape, int x, int y, GLfloat l);
};


#endif // DRAW_H_INCLUDED
