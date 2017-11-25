#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "entidad.h"
#include "escenario.h"
#include "claseallegro.h"
#include "personaje.h"
#include <allegro.h>

class enemigo : public entidad
{
    public:
        BITMAP *enemigo_mb;
        BITMAP *enemigo_;
        int posX, posY, fdireccion;



        enemigo(){
            posX=0;
            posY=0;
            fdireccion=0;
            enemigo_ = create_bitmap (30,30);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);
            }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

        void dibujar_fantasma(escenario escenario1){
            blit(enemigo_mb, enemigo_,0,0,0,0,30,30);
            draw_sprite(escenario1.escenario_, enemigo_, posX, posY);}

       /*void choqueFantasma(personaje pacman1,escenario escenario1,claseallegro juego){
            if ((pacman1.posY == posY && pacman1.posX == posX)|| (posY==(pacman1.posY-30) && posX ==(pacman1.posX-30))){
                for (int j=0; j<=5; j++){
                    clear(pacman1.pacman);
                    clear(escenario1.escenario_);
                    dibujar_mapa();
                        blit(pacman1.muerte,pacman1.pacman,j*30,0,0,0,30,30);
                        draw_sprite(escenario1.muerte,pacman1.pacman,pacman1.posX, pacman1.posY);
                        pantalla();
                        rest(90);}
                    pacman1.posX=30*10;
                pacman1.posY=30*12;
                pacman1.direccion=4;}}*/

        void movimientoFantasma(escenario escenario1){

            if (fdireccion==0){
                if(escenario1.mapa_1[posY/30][(posX-30)/30] != 'X')
                   posX-=30;
                else
                    fdireccion = rand()%3;}
            if (fdireccion==1){
                if(escenario1.mapa_1[posY/30][(posX+30)/30]!= 'X')
                    posX+=30;
                else
                    fdireccion = rand()%3;}
            if (fdireccion==2){
                if(escenario1.mapa_1[(posY-30)/30][(posX)/30]!= 'X')
                    posY-=30;
                else
                    fdireccion = rand()%3;}
            if (fdireccion==3){
                if(escenario1.mapa_1[(posY+30)/30][(posX)/30]!= 'X')
                    posY+=30;
                else
                    fdireccion = rand()%3;}
            if(posX<=-30)
                posX=870;
            else if (posX>=870)
                posX=-30;}

};

#endif // ENEMIGO_H
