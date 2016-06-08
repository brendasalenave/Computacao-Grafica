#ifndef PONTOS_H
#define PONTOS_H


class Pontos{
 /* variaveis */
    int mat[10][10]; //COORDENADAS originais centradas na origem

    int transf[10][10]; //coordenadas transformadas para exibicao na tela.
    float d = -10.0;

public:
    int ptosX[10];
    int ptosY[10];
    Pontos();
    void inicializa(int w, int h);
    void setPosition(int u, int x, int y);
    void setX(int u, int x);
    void setY(int u, int y);
    void projeta(float x, float y, float z, int *xt, int *yt);
    void transforma();

};

#endif // PONTOS_H
