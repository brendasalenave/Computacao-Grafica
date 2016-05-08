#ifndef NAVE_H
#define NAVE_H


class Nave{
    float x, y;
    float vel;
    float theta;
public:
    float vx[3], vy[3];
public:
    Nave();

    void rotacao(int cod, float ang);
    void translacao(float px, float py);
    void deslocamento();
    int getX();
    void setX(int px);
    int getY();
    void setY(int py);
    float getSpeed();
    void setSpeed(float s, int cod);
    float getTheta();
    void setTheta(float ang);
    void setShape(int px, int py);
    void desenha(float vecX[3], float vecY[3]);
};

#endif // NAVE_H
