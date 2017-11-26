#ifndef POWERUP_H
#define POWERUP_H
#include <allegro.h>
#include "escenario.h"
#include "personaje.h"
#include "enemigo.h"


class powerup
{
    public:
        BITMAP *coin;
        BITMAP *coin_mb;


       powerup(){
            coin = create_bitmap (30,30);
            coin_mb = load_bitmap("coin.bmp",NULL);
            }


        void dibujar_comida(escenario escenario1, personaje pacman1){
            blit(coin_mb, coin,0,0,0,0,30,30);
            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< 17; filas_m1++){
                for(col_m1=0; col_m1<40; col_m1++){
                    if (escenario1.mapa_1[filas_m1][col_m1]=='o')
                        draw_sprite(escenario1.escenario_,coin,col_m1*30,filas_m1*30);
                    if (pacman1.posY/30==filas_m1 && pacman1.posX/30 == col_m1)
                        escenario1.mapa_1[filas_m1][col_m1]=' ';}}
        }




};

#endif // POWERUP_H
