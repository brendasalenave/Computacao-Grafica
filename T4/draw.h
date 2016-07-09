#ifndef DRAW_H
#define DRAW_H


class Draw
{
public:
    Draw();
    void cube_(float x, float y, float z, float s, float rx, float ry, float rz, float ***m);
    void cylinder_(float radius, float layers, float length);
};

#endif // DRAW_H
