#include <stdlib.h>
#include "spline.h"

Spline::Spline(){(
    vecx = (int*)malloc(12 * sizeof(int));
    vecy = (int*)malloc(12 * sizeof(int));


}


void Spline::curva(){
    for (i = 0; i < np; i++){
        // %N faz com que a fique lista circular
        for (float t = 0.0; t <= 1.0; t += 0.0001){
            px = ((pow(1.0 - t, 3.0) / 6.0) * pontosx[i]) + (((3.0 *  pow(t, 3.0) - 6.0 * pow(t, 2.0) + 4.0) / 6.0) *
                 pontosx[(i + 1)]) + (((-3.0  *   pow(t, 3.0) + 3.0 * pow(t, 2.0) + 3.0 * t + 1) / 6.0) * pontosx[(i + 2)]) +
                 ((pow(t, 3.0) / 6.0)* pontosx[(i + 3)]);
            py = ((pow(1.0 - t, 3.0) / 6.0) * pontos[i]) + (((3.0 *  pow(t, 3.0) - 6.0 * pow(t, 2.0) + 4.0) / 6.0) *
                 pontos[(i + 1)]) + (((-3.0  *   pow(t, 3.0) + 3.0 * pow(t, 2.0) + 3.0 * t + 1) / 6.0) * pontos[(i + 2) ]) +
                 ((pow(t, 3.0) / 6.0)*pontos[(i + 3)]);

            point(px+200,py+200);
        }
    }
}

void Spline::inicializaPtos(){
    float ang;
    srand(time(NULL));
    int r = 100;
    i=0;
    for(ang=0;ang<PI2;ang+=(PI2/np)){
        pontos[i]=rand()%40+r;
        pontosx[i]=cos(ang)*pontos[i];
        pontos[i]=sin(ang)*pontos[i];
        i++;
    }
}
