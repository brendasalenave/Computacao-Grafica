#include "sweep.h"

Sweep::Sweep(){
    d = -10;
}

//projecao em perspectiva, assumindo camera na origem olhando para z negativo.
void Sweep::projeta(float x, float y, float z, int *xt, int *yt){
    *xt = (x*d)/z;
    *yt = (y*d)/z;
}
