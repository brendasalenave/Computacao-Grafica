#ifndef NAVE_H
#define NAVE_H


class Nave{
    float x, y;
    float theta;
public:
    float vx[3], vy[3];
public:
    Nave();

    void rotacao(float ang);
    int getX();
    void setX(int px);
    int getY();
    void setY(int py);
    float getTheta();
    void setTheta(float ang);
    void setShape(int px, int py);
    void desenha(float vecX[3], float vecY[3]);
};

#endif // NAVE_H
