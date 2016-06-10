#include <math.h>

#include "transformacoes.h"
#include "ponto.h"

Transformacoes::Transformacoes(){
    theta = 0;
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
    //resp.x = (p.x*d) / p.z;
    //resp.y = (p.y*d) / p.z;
    //resp.z = 0;

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
