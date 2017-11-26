#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidad.h"
#include "escenario.h"
#include "claseallegro.h"
#include "personaje.h"
#include <allegro.h>
#include <cstdlib>

class enemigo : public entidad
{
    public:
        BITMAP *enemigo_mb;
        BITMAP *enemigo_;

        enemigo(){
            enemigo_ = create_bitmap (30,30);
            enemigo_mb = load_bitmap("enemigo3.bmp",NULL);
            direccion=0;
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

        void dibujar_fantasma(escenario escenario1){
            blit(enemigo_mb, enemigo_,0,0,0,0,30,30);
            draw_sprite(escenario1.escenario_, enemigo_, posX, posY);}

        void movimientoFantasma(escenario escenario1){

            if (direccion==0){
                if(escenario1.mapa_1[posY/30][(posX-30)/30] != 'X')
                   posX-=30;
                else
                    direccion = rand()% 2 + 2;}
            if (direccion==1){
                if(escenario1.mapa_1[posY/30][(posX+30)/30]!= 'X')
                    posX+=30;
                else
                    direccion = rand()% 2 + 2 ;}
            if (direccion==2){
                if(escenario1.mapa_1[(posY-30)/30][(posX)/30]!= 'X')
                    posY-=30;
                else
                    direccion = rand()% 2 + 0;}
            if (direccion==3){
                if(escenario1.mapa_1[(posY+30)/30][(posX)/30]!= 'X')
                    posY+=30;
                else
                    direccion = rand()% 2 + 0;}
            if(posX<=-30)
                posX=1000;
            else if (posX>=1000)
                posX=-30;}

};

#endif // ENEMIGO_H
