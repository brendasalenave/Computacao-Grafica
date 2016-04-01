#ifndef __BULLET_H__
#define __BULLET_H__

class Bullet{

public:
    int x,y;
    double vel;

    void setPosition(int i, int j);
    int getX();
    int getY();
    void setX(int i);
    void setY(int j);

};

#endif // BULLET_H_INCLUDED
