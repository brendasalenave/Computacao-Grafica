#ifndef PONTO_H
#define PONTO_H


class Ponto{
   // float x;
    //float y;
    //float z;
public:
    float x;
    float y;
    float z;

    Ponto();

    void setX(float u);
    void setY(float u);
    void setZ(float u);
    float getX();
    float getY();
    float getZ();
};

#endif // PONTO_H
