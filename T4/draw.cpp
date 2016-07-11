// *********************************************************************
// T4 - Draga
//  Autora: Brenda Salenave Santana
//         07/2016
//
//  Funções utilizadas para realizar o desenho na janela de visualização.
//
// *
// *   bsantana@inf.ufsm.br
// *
//

#include "draw.h"
#include <QOpenGLFunctions_1_1>

#define PI_2 6.28318530718

Draw::Draw(){

}

void Draw::cube_(float x, float y, float z, float s, float rx, float ry, float rz, float ***m){
    glLoadIdentity();
    glTranslatef(x,y,z);
    // rotation about X axis
    glRotatef(rx,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(ry,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(rz,0.0,0.0,1.0);
    glScalef(0.5f,0.5f,0.5f);

    glBegin(GL_QUADS);                  // Draw The Cube Using quads
    for(int i = 0; i < 6; i++){
       for(int j = 0; j < 4; j++){
       //for(int k = 0; k < 3; k++){
           glVertex3f(GLfloat(m[i][j][0]), GLfloat(m[i][j][1]), GLfloat(m[i][j][2]));
       //}
       }
   }
   glEnd();            // End Drawing The Cube
}

void Draw::cylinder_(float radius, float layers, float length){
    for(int u=0; u< layers; u++) {
        float theta = ((float)u)* PI_2;
        float nextTheta = ((float)u+1)*PI_2;
        glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0, length, 0.0);
        glVertex3f(radius*cos(theta), length, radius*sin(theta));
        glVertex3f (radius*cos(nextTheta), length, radius*sin(nextTheta));
        /* the same vertices at the bottom of the cylinder*/

        glVertex3f (radius*cos(nextTheta), -length, radius*sin(nextTheta));
        glVertex3f(radius*cos(theta), -length, radius*sin(theta));
        glVertex3f(0.0, -length, 0.0);
        glEnd();

    }


}
