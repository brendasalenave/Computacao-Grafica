#ifndef PONTO_H
#define PONTO_H


class Ponto{
    float x,y,z;
public:
    Ponto();

    void setX(float u);
    void setY(float u);
    void setZ(float u);
    float getX();
    float getY();
    float getZ();
};

#endif // PONTO_H
