#include <allegro.h>
#include <cstdlib>

#include "personaje.h"
#include "entidad.h"
#include "claseallegro.h"
#include "escenario.h"
#include "enemigo.h"

int main()
{
    claseallegro juego;

    escenario mapa1;
    personaje pacman1;
    enemigo fantasma1;

    pacman1.setPosicion(30,120);
    fantasma1.setPosicion(30*14,30*10);

    while(!key[KEY_ESC]){

        pacman1.movimiento(mapa1);

        clear(mapa1.escenario_);

        mapa1.dibujar_mapa();
        pacman1.dibujarPersonaje(mapa1);
        fantasma1.dibujar_fantasma(mapa1);
        fantasma1.movimientoFantasma(mapa1);
        juego.pantalla(mapa1);
        rest(90);

        clear(pacman1.pacman);

        blit(pacman1.pacman_mb,pacman1.pacman,1*30,0,0,0,30,30);
        draw_sprite(mapa1.escenario_, pacman1.pacman, pacman1.posX,pacman1.posY);
        juego.pantalla(mapa1);
        rest(90);
    }
    return 0;
}
END_OF_MAIN();
