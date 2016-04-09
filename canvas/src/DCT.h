#ifndef __DCT_H__
#define __DCT_H__

#include <math.h>
#include "gl_canvas2d.h"

class DCT{
public:
    double fdct(int n, int m){
        int u, v, x, y;
        double val;
        for(u=0; u<8; u++){
            val = 0.0;
            for(x=0; x<8; x++){
                val += m1[x]*cos(((2.0*x+1.0)*PI*u)/16.0);
            }
            md[u] = (val/2.0)*C(u);
            printf("\nMD: %f ",md[u]);
        }
        return md;
    }

    int idct(int n, int m){
        int u, x, y;
        double pix, pi = M_PI;
        for(x=0; x < n-1; x++){
            for(y=0 ; y < y-1; y++){
                pix = 0.0;
                for(u=0; u < n-1; u++){
                        pix += C(u) * mat[u]*cos(((2.0*x+1.0)*pi*u)/(2*n));
                    }
                }
                mat[x] = round(pow((2/n), 0.5) * pow((2/m), 0.5) * (pix));
            }
        }
        return i;
    }


};

#endif

