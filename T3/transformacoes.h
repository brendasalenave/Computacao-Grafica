// *********************************************************************
//  Autora: Brenda S. Santana
//         06/2016
// *
// *   bsantana@inf.ufsm.br
// *
// Objetivo da Classe: Implementar funções de transformações a serem aplicadas sobre o objeto.
//

#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H

#include <ponto.h>
#include <vector>
using namespace std;


class Transformacoes{
    float theta;
    float ang;

public:
    Transformacoes();
    std::vector<Ponto> cria(std::vector<Ponto> p, std::vector<Ponto>::size_type t, int cod, int cod2);
    Ponto projeta( Ponto p );
    Ponto translada(Ponto p);
    Ponto escala(Ponto p);
    Ponto rotacionaX(Ponto p );
    Ponto rotacionaY(Ponto p );


};

#endif // TRANSFORMACOES_H
