#ifndef __DCT_H__
#define __DCT_H__

#include "gl_canvas2d.h"

#define PI 3.14159265

class DCT{
    int m[8];
    int m2[8];
    double mr[8];
    public:
    int t;

public:
    DCT(){
      t = 0;
    }

    double* fdct(int m[8]){
        int u, x;
        double p;
        for(u=0; u<8; u++){
            p = 0.0;
            for(x=0; x<8; x++){
                p += m[x]*cos(((2.0*x+1.0)* PI *u)/16.0);
            }
            mr[u] = (p/2.0)*C(u);
            printf("\nMR: %f ",mr[u]);
        }
        return mr;
    }

    int *idct(double mr[8]){
      int u, x;
      double p;
      for(x=0; x<8; x++){
            p = 0.0;
            for(u=0; u<8; u++){
                p += C(u)*mr[u]*cos(((2.0*x+1)*PI*u)/16.0);
            }
            m2[x] = (int)(p/2.0);
            printf("M2: %d",m2[x]);
      }
      return m2;
    }

    double C(int w){
      if(w==0)
         return 0.707106781186;  /* 1/sqrt(2) */
      return 1.0;
   }

    void threshold(int mat[8]){
        for(int u = 0; u < 8; u++){
            if(mat[u] < t)
                mat[u] = 0;
        }
    }
};

#endif

