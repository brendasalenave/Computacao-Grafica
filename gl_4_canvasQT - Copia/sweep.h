#ifndef SWEEP_H
#define SWEEP_H


class Sweep {
    int z;
    float d;
public:
    Sweep();

    void projeta(float x, float y, float z, int *xt, int *yt);
};

#endif // SWEEP_H
