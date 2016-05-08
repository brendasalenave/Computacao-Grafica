#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H


class Transformacoes{
    int tx, ty;

public:
    Transformacoes();

    float rotacaoX(float x, float y, float theta, int cod);

    float rotacaoY(float x, float y, float theta, int cod);

    float translacaoX(float x);

    float translacaoY(float y);

    float dirX(float x, float theta);

    float dirY(float y, float theta);

    float deslocamentoX(float x, float theta, float vel);

    float deslocamentoY(float y, float theta, float vel);

};

#endif // TRANSFORMACOES_H
