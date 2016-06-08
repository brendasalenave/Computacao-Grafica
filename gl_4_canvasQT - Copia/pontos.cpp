#include "pontos.h"

Pontos::Pontos(){
    d = -10.0;

}

void Pontos::inicializa(int w, int h){
    int i;
    int l =(h-40)/10;
    for(i = 0; i < 10; i++){
        ptosX[i] = w/2;
    }
    for(i = 0; i < 10; i++){
        ptosY[i] = ((i+1)*l);
    }
}

void Pontos::setPosition(int u, int x, int y){
    ptosX[u] = x;
    ptosY[u] = y;
}

void Pontos::setX(int u, int x){
    ptosX[u] = x;
}

void Pontos::setY(int u, int y){
    ptosY[u] = y;
}

void Pontos::projeta(float x, float y, float z, int *xt, int *yt){
    *xt = (x*d)/z;
    *yt = (y*d)/z;
}

void Pontos::transforma() {
   for(int x=0; x < 10; x++){
      for(int z=0; z < 10; z++){
           //copia os pontos originais
           //transf[x][z] = mat[x][z];

           //rotacao no eixo x
           //transf[x][z] = rotacionaX( transf[x][z] );

           //translacao no eixo z
           //transf[x][z] = translada( transf[x][z] );

           //projecao em perspectiva
           //transf[x][z] = projeta(transf[x][z] );
      }
   }
}
