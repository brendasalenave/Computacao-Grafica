#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H

#include <ponto.h>
#include <vector>
using namespace std;


class Transformacoes{
    float theta;

public:
    Transformacoes();
    std::vector<Ponto> cria(std::vector<Ponto> p, std::vector<Ponto>::size_type t, int cod);
    Ponto projeta( Ponto p );
    Ponto rotacionaY(Ponto p );
    Ponto translada(Ponto p);

};

#endif // TRANSFORMACOES_H
