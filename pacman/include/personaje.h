#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"
#include "escenario.h"
#include "claseallegro.h"
#include "enemigo.h"

#include <allegro.h>


class personaje : public entidad
{
    public:
        BITMAP *pacman_mb;
        BITMAP *pacman;
        BITMAP *muerte;

        personaje(){
        posX = 0;
        posY = 0;
        direccion = 1;
        pacman_mb = load_bitmap("pacman.bmp",NULL);
        muerte = load_bitmap("muerte.bmp",NULL);
        pacman = create_bitmap(30,30);

        }

        void setPosicion(int x, int y){
            posX=x;
            posY=y;
        }

        void dibujarPersonaje(escenario escenario1, bool r){
            if (r==true){
                blit(pacman_mb, pacman, direccion*30,0,0,0,30,30);
                draw_sprite(escenario1.escenario_, pacman,posX, posY);}

            else{
                blit(pacman_mb,pacman,1*30,0,0,0,30,30);
                draw_sprite(escenario1.escenario_, pacman,posX, posY);}
        }

        void movimiento( escenario escenario1, int numJugadores){


            if (numJugadores==1){
                if (key[KEY_LEFT]) direccion=2;
                else if (key[KEY_RIGHT])direccion=0;
                else if (key[KEY_UP]) direccion=4;
                else if (key[KEY_DOWN]) direccion=3; }

            if(numJugadores==2){
                if (key[KEY_A]) direccion=2;
                else if (key[KEY_D])direccion=0;
                else if (key[KEY_W]) direccion=4;
                else if (key[KEY_S]) direccion=3; }

            if (numJugadores==3){
                if (key[KEY_J]) direccion=2;
                else if (key[KEY_L])direccion=0;
                else if (key[KEY_I]) direccion=4;
                else if (key[KEY_K]) direccion=3; }

            if(direccion==2) {
                if (escenario1.mapa_1[posY/30][(posX-30)/30] != 'X')
                    posX -=30;
                else
                    direccion=1;
            }
            if(direccion==0) {
                if (escenario1.mapa_1[posY/30][(posX+30)/30] != 'X')
                    posX +=30;
                else
                    direccion=1;
                }
            if (direccion==4) {
                if (escenario1.mapa_1[(posY-30)/30][posX/30]!= 'X')
                    posY -=30;
                else
                    direccion=1;
                    }
            if(direccion==3) {
                 if (escenario1.mapa_1[(posY+30)/30][posX/30]!= 'X')
                    posY +=30;
                else
                    direccion=1;
            }

        }

        void comer(escenario mapa1){
            for (int filas_m1=0; filas_m1< 17; filas_m1++){
                for(int col_m1=0; col_m1<40; col_m1++){
                    if (posY/30==filas_m1 &&posX/30 == col_m1)
                        mapa1.mapa_1[filas_m1][col_m1]=' ';}}

        }

        void choqueFantasma(enemigo en1,escenario escenario1, claseallegro juego){

            if ((en1.posY == posY && en1.posX == posX) || (posY == en1.posY-30 && posX == en1.posX-30) || (posY == en1.posY+30 && posX == en1.posX+30)){
                for (int j=0; j<=6;j++){
                    clear(pacman);
                    clear(escenario1.escenario_);
                    escenario1.dibujar_mapa();
                        blit(muerte,pacman,j*30,0,0,0,30,30);
                        draw_sprite(escenario1.escenario_,pacman,posX, posY);
                        juego.pantalla(escenario1);
                        rest(90);}
                    posX=30*10;
                    posY=30*12;
                    direccion=1;}}



};


#endif // PERSONAJE_H
