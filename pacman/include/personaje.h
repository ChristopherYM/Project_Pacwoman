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



        void movimiento( escenario e1, int numJugadores){


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

            int d2=e1.mapa_1[posY/30][(posX-30)/30];
            int d0=e1.mapa_1[posY/30][(posX+30)/30];
            int d4=e1.mapa_1[(posY-30)/30][posX/30];
            int d3=e1.mapa_1[(posY+30)/30][posX/30];

            if(direccion==2) {
            if ((d2 != 'V') && (d2 != 'D')&& (d2 != 'C')&& (d2 != 'N') && (d2 != 'S') && (d2 != 'B') && (d2 != 'J') && (d2 != 'R') && (d2 != 'E') && (d2 != 'W')&& (d2 != 'L')&& (d2 != 'H') )
                    posX -=30;
                else
                    direccion=1;
            }
            if(direccion==0) {
                if ((d0 != 'V') && (d0 != 'A')&& (d0 != 'X')&& (d0 != 'N') && (d0 != 'M') && (d0 != 'B') && (d0 != 'J') && (d0 != 'R') && (d0 != 'E')&& (d0 != 'Q') && (d0 != 'W')&& (d0 != 'L')&& (d0 != 'H'))
                    posX +=30;
                else
                    direccion=1;
                }
            if (direccion==4) {
                if ((d4 != 'X') && (d4!= 'Z')&& (d4 != 'C')&& (d4 != 'K') && (d4 != 'Q') && (d4 != 'M') && (d4 != 'B') && (d4 != 'D') && (d4 != 'R') && (d4 != 'N'))
                    posY -=30;
                else
                    direccion=1;
                    }
            if(direccion==3) {
                 if ((d3 != 'X') && (d3!= 'Z')&& (d3 != 'C')&& (d3 != 'K') && (d3 != 'Q') && (d3 != 'M') && (d3 != 'B') && (d3 != 'D') && (d3 != 'R')&& (d3 != 'A')&& (d3 != 'N')&& (d3 != 'S') && (d3 != 'W')&& (d3 != 'L')&& (d3 != 'E'))
                    posY +=30;
                else
                    direccion=1;
            }
            if(posX<=-30)
                posX=1170;
            else if (posX>=1170)
                posX=-30;
            if (posY<=-30)
                posY=510;
            else if (posY>=510)
                posY=-30;
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
                    posX=30*19;
                    posY=30*12;
                    direccion=1;}}



};


#endif // PERSONAJE_H
