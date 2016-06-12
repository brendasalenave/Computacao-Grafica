#include <math.h>
//#include <vector>

#include "transformacoes.h"
#include "ponto.h"

using namespace std;


Transformacoes::Transformacoes(){
    theta = 6.28;
}

std::vector<Ponto> Transformacoes::cria(std::vector<Ponto> p, std::vector<Ponto>::size_type t){
    std::vector<Ponto> ponto2;

    for(int u=0; u <t ; u++){
        for(float z=0; z<=theta; z+=0.001){
            Ponto resp;
            //resp.x =cos(z) * p[u].x;
            resp.setX(cos(z) * p[u].getX());
            resp.setY(p[u].getY());
            resp.setZ(sin(z) * 6);

            resp = translada(resp);
            resp = rotacionaY(resp);
            resp = projeta(resp);
            ponto2.push_back(resp);
      }
    }
    return ponto2;
}

Ponto Transformacoes::projeta( Ponto p ){
    float d = -10.0;
    Ponto resp;

    float x = p.getX();
    float y = p.getY();
    float z = p.getZ();

    resp.setX((x*d)/z);
    resp.setY((y*d)/z);
    resp.setZ(0);

    return resp;
}

Ponto Transformacoes::rotacionaY(Ponto p ){
    Ponto resp;
    theta += 0.00001;

    float x = p.getX();
    float y = p.getY();
    float z = p.getZ();

    resp.setX(sin(theta)*x - cos(theta)*z);
    resp.setY(y);
    resp.setZ(sin(theta)*x + cos(theta)*z);

    //resp.x = p.x;
    //resp.y = cos(theta)*p.y - sin(theta)*p.z;
    //resp.z = sin(theta)*p.y + cos(theta)*p.z;

    return resp;
}

Ponto Transformacoes::translada(Ponto p){
    Ponto resp;

    float x = p.getX();
    float y = p.getY();
    float z = p.getZ();

    resp.setX(x);
    resp.setY(y - 10);
    resp.setZ(z - 12);

    //resp.x = p.x;
    //resp.y = p.y - 10 ;
    //resp.z = p.z - 12;

    return resp;
}
