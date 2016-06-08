#ifndef PONTOS_H
#define PONTOS_H


class Pontos{
 /* variaveis */
public:
    int ptosX[10];
    int ptosY[10];
    Pontos();
    void inicializa(int w, int h);
    void setPosition(int u, int x, int y);
    void setX(int u, int x);
    void setY(int u, int y);


};

#endif // PONTOS_H
