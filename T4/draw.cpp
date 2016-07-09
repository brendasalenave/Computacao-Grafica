#include "draw.h"
#include <QOpenGLFunctions_1_1>


Draw::Draw()
{

}

void Draw::cube_(float x, float y, float z, float s, float rx, float ry, float rz, float ***m){
    glLoadIdentity();
    glTranslatef(x,y,z);
    glScalef(0.5f,0.5f,0.5f);

    // rotation about X axis
    glRotatef(rx+20,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(ry+30,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(rz,0.0,0.0,1.0);

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
