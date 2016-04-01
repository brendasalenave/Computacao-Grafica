#include <stdio.h>
#include <glut.h>
#include <freeglut_ext.h>
#include "draw.h"

    void Draw::line2d(int x, int y, int xf, int yf, GLfloat l){
        glColor3b(0.0,0.0,0.0);
        glLineWidth(l);
        glBegin(GL_LINES);
        glVertex2i(x,y);
        glVertex2i(xf,yf);
        glEnd();
        glFlush();
    }

    void Draw::point2d(int x, int y, GLfloat l){
        glColor3b(0.0,255.0,255.0);
        glPointSize(l);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
    }

    //desenha uma foram conforme um vetor de shape
    void Draw::ship2d(int **shape, int x, int y, GLfloat l){
        glColor3b(0.0,255.0,255.0);
        glBegin(GL_POLYGON);
        for(i=0;i<3;i++){
            glVertex2i(shape[i][0]+x,shape[i][1]+y);
        }
        glEnd();
        glFlush();
    }
