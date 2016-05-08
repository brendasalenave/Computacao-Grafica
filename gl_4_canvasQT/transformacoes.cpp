#include <math.h>
#include "transformacoes.h"

Transformacoes::Transformacoes(){
    tx = 0.2;
    ty = 0.2;

}

float Transformacoes::rotacaoX(float x, float y, float theta, int cod){
    if(cod == 0)
        return (x = x * cos(theta) - y * sin(theta));
    else
        return (x = x * cos(theta) + y * sin(theta));
}

float Transformacoes::rotacaoY(float x, float y, float theta, int cod){
    if(cod == 0)
        return (y = x * sin(theta) + y * cos(theta));
    else
        return (y = -1 * x * sin(theta) + y * cos(theta));
}

float Transformacoes::translacaoX(float x){
    return (x += tx);
}

float Transformacoes::translacaoY(float y){
    return (y += ty);
}

float Transformacoes::dirX(float x, float theta){
    return (x = cos(theta));
}

float Transformacoes::dirY(float y, float theta){
    return (y = sin(theta));
}

float Transformacoes::deslocamentoX(float x, float theta, float vel){
    return (x += cos(theta) * vel);
}

float Transformacoes::deslocamentoY(float y, float theta, float vel){
    return (y += sin(theta) * vel);
}
