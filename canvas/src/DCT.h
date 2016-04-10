#ifndef __DCT_H__
#define __DCT_H__

#include <math.h>
#include <stdlib.h>
#include "gl_canvas2d.h"

class DCT{
    int *m;
    int *m2;
    double *mr;
    int t;

public:
    DCT(){
      t = 0;
      m  = (int)malloc(8 * sizeof(int));
      m2 = (int)malloc(8 * sizeof(int));
      mr = (double)malloc(8 * sizeof(double));
    }

    double fdct(int m[8]){
        int u, v, x, y;
        double p;
        for(u=0; u<8; u++){
            p = 0.0;
            for(x=0; x<8; x++){
                p += m[x]*cos(((2.0*x+1.0)*PI*u)/16.0);
            }
            mr[u] = (p/2.0)*C(u);
            printf("\nMD: %f ",mr[u]);
        }
        return mr;
    }

    int idct(int mr[8]){
      int u, v, x, y;
      double p;
      for(x=0; x<8; x++){
            p = 0.0;
            for(u=0; u<8; u++){
                p += C(u)*mr[u]*cos(((2.0*x+1)*M_PI*u)/16.0);
            }
            m2[x] = (int)(p/2.0);
            printf("M2: %d",m2[x]);
      }
      return m2;
    }

    void threshold(int mat[8]){
        for(int u = 0; i < 8; i++){
            if(mat[u] > t)
                mat[u] = 0;
        }
    }
};

#endif

