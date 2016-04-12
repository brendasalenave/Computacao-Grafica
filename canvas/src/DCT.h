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

    double* fdct(std::vector<char>& str){
        int u, x;
        double p;
        double* f = (double*)malloc(128*sizeof(double));

        for(u=0; u < str.size(); u++){
            p = 0.0;
            for(x=0; x < str.size(); x++){
                p += str[x]*cos(((2.0*x+1.0)* PI *u)/256);
            }
            f[u] = p*C(u);
            //printf("\nMR: %f ",mr[u]);
        }
        return f;
    }

    int* idct(double* f){
      int u, x;
      int *mr = (int*)malloc(128 * sizeof(int));
      double p;

      for(x = 0; x < 128; x++){
            p = 0.0;
            for(u = 0; u < 128; u ++){
                p += C(u)*f[u]*cos(((2.0*x+1.0)*PI*u)/256);
            }
            mr[x] = (int)(ceil(p));
      }
      return mr;
    }

    double C(int w){
        if(w == 0)
            return 0.088388347;
        else
            return 0.125;


      /*if(w==0)
         return 0.707106781186;  // 1/sqrt(2)
      return 1.0;*/
   }

     void setThreshold(int u){
        t = u;
        char str[3];
        sprintf (str, "%d", u);
        text(703, 76, str);
     }

     int getThreshold(){
        return t;
     }

    void threshold(double mat[128]){
        for(int u = 0; u < 128; u++)
            if(mat[u] < t) mat[u] = 0;

    }

    double* fdctSin(float* m){
        int u, x;
        double p;
        double* f = (double*)malloc(128*sizeof(double));

        for(u=0; u < 128; u++){
            p = 0.0;
            for(x=0; x < 128; x++){
                p += m[x]*cos(((2.0*x+1.0)* PI *u)/256);
            }
            f[u] = p*C(u);
            //printf("\nMR: %f ",mr[u]);
        }
        return f;
    }

    int* idctSin(double* f){
      int u, x;
      int *mr = (int*)malloc(128 * sizeof(int));
      double p;

      for(x = 0; x < 128; x++){
            p = 0.0;
            for(u = 0; u < 128; u ++){
                p += C(u)*f[u]*cos(((2.0*x+1.0)*PI*u)/256);
            }
            mr[x] = (int)(ceil(p));
      }
      return mr;
    }

};

#endif

