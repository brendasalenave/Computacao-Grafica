#ifndef TIRO_H
#define TIRO_H


class Tiro{
    float x, y;
    float alpha;
    float vel;


public:
    Tiro();

    void setPos(float px, float py);
    int getX();
    int getY();
    void setX(int px);
    void setY(int py);
    float getSpeed();
    void setSpeed(float speed);
    void setAlpha(float theta);
    float getAlpha();
};

#endif // TIRO_H
