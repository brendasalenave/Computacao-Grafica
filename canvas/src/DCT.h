#ifndef __DCT_H__
#define __DCT_H__

#include <math.h>
#include "gl_canvas2d.h"

class DCT{
public:
    double fdct(int n, int m){
        int u, x, y;
        double pix, pi = M_PI;
        for(u=0; u < n-1; u++){
                pix = 0.0;
                for(x=0; x < n-1; x++){
                    for(y=0; y < m-1; y++){
                        pix += i.mat[x]*cos(((2.0*x+1.0)*pi*u)/(2*n));
                    }
                }
                m.mat[u] = pow((2/n), 0.5) * pow((2/m), 0.5) * (pix) * C(u);
            }
        }
        return m;
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

