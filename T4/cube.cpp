#include <QOpenGLFunctions_1_1>
#include <stdio.h>
#include "cube.h"

Cube::Cube(){
    //float ***form;
    form = (float***) malloc(6*sizeof(float***));
    for (int i=0; i<6; i++) {
        form[i] = (float**) malloc(4*sizeof(float**));
        for (int j=0; j<4; j++) {
            form[i][j] = (float*) malloc(3*sizeof(float*));
            for (int k=0; k<3; k++) {
                form[i][j][k] = *(float*)malloc(sizeof(float));
            }
        }
    }
}


float*** Cube::setForm(float x, float y, float z, float r, float g, float b){

    glColor3f((GLfloat)r,(GLfloat)g,(GLfloat)b);        // Color Yellow
    /* Top Face */
    form[0][0][0] =  1 * x;
    form[0][0][1] =  1 * y;
    form[0][0][2] = -1 * z;

    form[0][1][0] = -1 * x;
    form[0][1][1] =  1 * y;
    form[0][1][2] = -1* z;

    form[0][2][0] = -1 * x;
    form[0][2][1] =  1 * y;
    form[0][2][2] =  1 * z;

    form[0][3][0] = 1 * x;
    form[0][3][1] = 1 * y;
    form[0][3][2] = 1 * z;

    /* Bottom */
    form[1][0][0] =  1 * x;
    form[1][0][1] = -1 * y;
    form[1][0][2] =  1 * z;

    form[1][1][0] = -1 * x;
    form[1][1][1] = -1 * y;
    form[1][1][2] =  1 * z;

    form[1][2][0] = -1 * x;
    form[1][2][1] = -1 * y;
    form[1][2][2] = -1 * z;

    form[1][3][0] =  1 * x;
    form[1][3][1] = -1 * y;
    form[1][3][2] = -1 * z;

    /* Front */
    form[2][0][0] =  1 * x;
    form[2][0][1] =  1 * y;
    form[2][0][2] =  1 * z;

    form[2][1][0] = -1 * x;
    form[2][1][1] =  1 * y;
    form[2][1][2] =  1 * z;

    form[2][2][0] = -1 * x;
    form[2][2][1] = -1 * y;
    form[2][2][2] =  1 * z;

    form[2][3][0] =  1 * x;
    form[2][3][1] = -1 * y;
    form[2][3][2] =  1 * z;

    /* Back */
    form[3][0][0] =  1 * x;
    form[3][0][1] = -1 * y;
    form[3][0][2] = -1 * z;

    form[3][1][0] = -1 * x;
    form[3][1][1] = -1 * y;
    form[3][1][2] = -1 * z;

    form[3][2][0] = -1 * x;
    form[3][2][1] =  1 * y;
    form[3][2][2] = -1 * z;

    form[3][3][0] =  1 * x;
    form[3][3][1] =  1 * y;
    form[3][3][2] = -1 * z;

    /* Left */
    form[4][0][0] = -1 * x;
    form[4][0][1] =  1 * y;
    form[4][0][2] =  1 * z;

    form[4][1][0] = -1 * x;
    form[4][1][1] =  1 * y;
    form[4][1][2] = -1 * z;

    form[4][2][0] = -1 * x;
    form[4][2][1] = -1 * y;
    form[4][2][2] = -1 * z;

    form[4][3][0] = -1 * x;
    form[4][3][1] = -1 * y;
    form[4][3][2] =  1 * z;

    /* Right */
    form[5][0][0] =  1 * x;
    form[5][0][1] =  1 * y;
    form[5][0][2] = -1 * z;

    form[5][1][0] =  1 * x;
    form[5][1][1] =  1 * y;
    form[5][1][2] =  1 * z;

    form[5][2][0] =  1 * x;
    form[5][2][1] = -1 * y;
    form[5][2][2] =  1 * z;

    form[5][3][0] =  1 * x;
    form[5][3][1] = -1 * y;
    form[5][3][2] = -1 * z;

    return form;
}

void Cube::setNormalArray(){
    //glNormal3f()
}
