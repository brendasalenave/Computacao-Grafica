#include <math.h>
#include "transformacoes.h"

Transformacoes::Transformacoes(){

}

float Transformacoes::rotacaoX(float x, float y, float theta){
    return (x = x * cos(theta) - y * sin(theta));
    //y = x * sin(theta) + y * cos(theta);
}

float Transformacoes::rotacaoY(float x, float y, float theta){
    //x = x * cos(theta) - y * sin(theta);
    return (y = x * sin(theta) + y * cos(theta));
}

float Transformacoes::translacaoX(float x){
    return (x += 1);
}

float Transformacoes::translacaoY(float y){
    return (y += 1);
}

float Transformacoes::dirX(float x, float theta){
    return (x = cos(theta));
}

float Transformacoes::dirY(float y, float theta){
    return (y = sin(theta));
}
