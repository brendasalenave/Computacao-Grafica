#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H


class Transformacoes{

public:
    Transformacoes();

    float rotacaoX(float x, float y, float theta);

    float rotacaoY(float x, float y, float theta);

    float translacaoX(float x);

    float translacaoY(float y);

    float dirX(float x, float theta);

    float dirY(float y, float theta);


};

#endif // TRANSFORMACOES_H
