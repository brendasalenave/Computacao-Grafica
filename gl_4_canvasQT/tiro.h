#ifndef TIRO_H
#define TIRO_H


class Tiro{
    int x, y;
    float alpha;
    float vel;


public:
    Tiro();

    void setPos(int px, int py);
    int getX();
    int getY();
    void setX(int px);
    void setY(int py);
};

#endif // TIRO_H
