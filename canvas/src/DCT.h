/*********************************************************************
// Computacao Grafica - Trabalho 1.
//  Autor: Brenda Salenave Santana
//         2016/1
//  E-mail: bsantana@inf.ufsm.br
//
//  Classe DCT: Classe utilizada para implementar metodos relacionados
//  a DCT, IDCT e Threshold.
// *********************************************************************/

#ifndef __DCT_H__
#define __DCT_H__

#include "gl_canvas2d.h"

#define PI 3.14159265

class DCT{
    int r;
    public:
    int t;

public:
    DCT(){
      t = 0;
      r = 0;
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
    }

    /* Metodo utilizado para setar o valor do threshold */
    void setThreshold(int u){
        t = u;
        char str[3];
        sprintf (str, "%d", u);
        text(r+191, 76, str);
     }

     /* Metodo utilizado para retornar o valor atual do threshold */
    int getThreshold(){
        return t;
     }

    /* Metodo utilizado para aplicacao do threshold */
    void threshold(double mat[128]){
        if(t == 0)
            return;

        for(int u = 0; u < 128; u++)
            if(mat[u] < t) mat[u] = 0;

    }

    /* Metodo utilizado para setar a variavel r, utilizada para o redimensionamento */
    void setRazao(int razao){
        r = razao;
    }

};

#endif

