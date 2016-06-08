#include "pontos.h"

Pontos::Pontos(){

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
