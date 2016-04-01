#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ship.h"
#include "Bullet.h"
#include "Draw.h"

    Ship::Ship(void){
        x=50;
        y=20;
    }

    int** Ship::getShape(){
        return shape;
    }

    void Ship::setShape(){
        shape = new int*[3];
        for(int i = 0; i < 3; i++)
            shape[i] = new int[2];
        shape[0][0]=0;
        shape[0][1]=0;
        shape[1][0]=20;
        shape[1][1]=0;
        shape[2][0]=10;
        shape[2][1]=10;
    }

    void Ship::setPosition(int i, int j){
        this->x = i;
        this->y = j;
    }

    int Ship::getX(){
        return x;
    }

    int Ship::getY(){
        return y;
    }

    void Ship::iniciaShoots(){
        fbs *tmp = (fbs *) malloc(sizeof(fbs));
        this->f = tmp;
    }

    void Ship::shoot(){
        fbs *s = (fbs *) malloc(sizeof(fbs));
        s->prox=NULL;
        s->b = new Bullet();
        s->b->setPosition(x,y);
        fbs *tmp = this->f;
        while(tmp->prox!=NULL){
            tmp=tmp->prox;
        }
        tmp->prox=s;
    }

    void Ship::removeShoot(){
        fbs *tmp = f->prox;
        f->prox = tmp->prox;
        free(tmp);
    }

    void Ship::imprimeShoots(){
        fbs *tmp = this->f;
        if(tmp->prox==NULL){
            printf("Vazio");
        }
        while(tmp->prox!=NULL){
            printf("%d ",1);
            tmp=tmp->prox;
        }
        printf("\n");
    }

    void Ship::liberaShoots(void){
        fbs *tmp = this->f;
        while(tmp->prox!=NULL){
            tmp = tmp->prox;
            if(tmp->b->getY()>200){
                this->f->prox = tmp->prox;
                free(tmp);
                imprimeShoots();
            }
        }
    }

    void Ship::renderShoots(){
        fbs *tmp = this->f;
        while(tmp->prox!=NULL){
            tmp=tmp->prox;
            this->d->point2d(tmp->b->getX()+10,tmp->b->getY()+12,4.0);
        }
    }

    void Ship::updateBulletsPosition(){
        fbs *tmp = this->f;
        while(tmp->prox!=NULL){
            tmp=tmp->prox;
            tmp->b->setY(tmp->b->getY()+5);
        }
    }


