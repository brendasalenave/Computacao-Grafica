#ifndef CUBE_H
#define CUBE_H


class Cube{
    float ***form;
public:
    Cube();
    float*** setForm(float x, float y, float z, float r, float g, float b);
    void setNormalArray();
};

#endif // CUBE_H
