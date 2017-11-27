#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "escenario.h"
#include "entidad.h"



#include <allegro.h>
#include <cstdlib>

class enemigo : public entidad
{
    public:
        BITMAP *enemigo_mb;
        BITMAP *enemigo_;

        enemigo(){
            posX=0;
            posY=0;
            direccion=2;
            enemigo_ = create_bitmap (30,30);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

        void dibujar_fantasma(escenario escenario1){
            blit(enemigo_mb, enemigo_,0,0,0,0,30,30);
            draw_sprite(escenario1.escenario_, enemigo_, posX, posY);}



        void movimientoFantasma(escenario e1){

            int d0=e1.mapa_1[posY/30][(posX-30)/30];
            int d1=e1.mapa_1[posY/30][(posX+30)/30];
            int d2=e1.mapa_1[(posY-30)/30][posX/30];
            int d3=e1.mapa_1[(posY+30)/30][posX/30];

            if (direccion==0){
                if((d0 != 'V') && (d0 != 'D')&& (d0 != 'C')&& (d0 != 'N') && (d0 != 'S') && (d0 != 'B') && (d0 != 'J') && (d0 != 'R') && (d0 != 'E')&& (d0 != 'H'))
                   posX-=30;
                else
                    direccion = rand()% 2 + 2;}
            if (direccion==1){
                if((d1 != 'V') && (d1 != 'A')&& (d1 != 'X')&& (d1 != 'N') && (d1 != 'M') && (d1 != 'B') && (d1 != 'J') && (d1 != 'R') && (d1 != 'E')&& (d1 != 'Q'))
                    posX+=30;
                else
                    direccion = rand()% 2 + 2 ;}
            if (direccion==2){
                if((d2 != 'X') && (d2!= 'Z')&& (d2 != 'C')&& (d2 != 'K') && (d2 != 'Q') && (d2 != 'M') && (d2 != 'B') && (d2 != 'D') && (d2 != 'R')&&(d2!='L'))
                    posY-=30;
                else
                    direccion = rand()% 2 + 0;}
            if (direccion==3){
                if((d3 != 'X') && (d3!= 'Z')&& (d3 != 'C')&& (d3 != 'K') && (d3 != 'Q') && (d3 != 'M') && (d3 != 'B') && (d3 != 'D') && (d3 != 'R') && (d3 != 'W')&& (d3 != 'L'))
                    posY+=30;
                else
                    direccion = rand()% 2 + 0;}


            if(posX<=-30)
                posX=1170;
            else if (posX>=1170)
                posX=-30;
            if (posY<=-30)
                posY=510;
            else if (posY>=510)
                posY=-30;}



};



#endif // ENEMIGO_H
