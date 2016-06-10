#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H

#include <ponto.h>

class Transformacoes{
    float theta;
public:
    Transformacoes();
    Ponto projeta( Ponto p );
    Ponto rotacionaY(Ponto p );
};

#endif // TRANSFORMACOES_H
