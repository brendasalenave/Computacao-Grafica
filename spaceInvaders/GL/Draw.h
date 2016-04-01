#ifndef __DRAW_H__
#define __DRAW_H__

class draw{
public:
    void line2d(int x, int y, int xf, int yf, GLfloat l);
    void point2d(int x, int y, GLfloat l);
    void ship2d(int **shape, GLfloat l);
};


#endif // DRAW_H_INCLUDED
