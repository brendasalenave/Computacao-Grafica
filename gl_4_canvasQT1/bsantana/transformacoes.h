// *********************************************************************
//  Autor: Brenda S. Santana
//         05/2016
// *
// *   bsantana@inf.ufsm.br
// *
// Objetivo da Classe: Implementar funções de transformações geométricas.
//

#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H


class Transformacoes{


public:
    Transformacoes();

    float rotacaoX(float x, float y, float theta, int cod);

    float rotacaoY(float x, float y, float theta, int cod);

    float deslocamentoX(float x, float theta, float vel);

    float deslocamentoY(float y, float theta, float vel);

};

#endif // TRANSFORMACOES_H
