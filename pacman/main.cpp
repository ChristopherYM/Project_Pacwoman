#include <allegro.h>
#include <cstdlib>

#include "personaje.h"
#include "entidad.h"
#include "claseallegro.h"
#include "escenario.h"
#include "enemigo.h"
#include "powerup.h"



int main()
{
    claseallegro juego;

    escenario mapa1;
    personaje pacman1;
    pacman1.setPosicion(300,360);

    enemigo fantasma1;
    fantasma1.setPosicion(30*14,30*10);


    powerup comida1;

    while(!key[KEY_ESC]){

        pacman1.movimiento(mapa1,1);
        for (int filas_m1=0; filas_m1< 17; filas_m1++){
                for(int col_m1=0; col_m1<40; col_m1++){
                    if (pacman1.posY/30==filas_m1 && pacman1.posX/30 == col_m1)
                        mapa1.mapa_1[filas_m1][col_m1]=' ';}}

        clear(mapa1.escenario_);

        comida1.dibujar_comida(mapa1,pacman1);
        mapa1.dibujar_mapa();

        pacman1.dibujarPersonaje(mapa1,true);

        fantasma1.dibujar_fantasma(mapa1);
        fantasma1.movimientoFantasma(mapa1);
        //pacman1.choqueFantasma(fantasma1,mapa1);
        juego.pantalla(mapa1);
        rest(90);

        clear(pacman1.pacman);

        pacman1.dibujarPersonaje(mapa1, false);

        juego.pantalla(mapa1);
        rest(90);
    }
    return 0;
}
END_OF_MAIN();
