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
