#include <allegro.h>
#include <cstdlib>

#include "personaje.h"
#include "entidad.h"


#define Filas 21
#define Columnas 31

BITMAP *escenario;
BITMAP *roca;
BITMAP *pacman_mb;
BITMAP *pacman;
BITMAP *enemigo_mb;
BITMAP *enemigo;
BITMAP *coin;
BITMAP *muerte;


personaje pacman1;
pacman1.setPosicion(30*10,30*10);

personaje enemigo1;
enemigo1.setPosicion(30*14, 30*13);



char mapa_1[Filas][Columnas] = {
    "                              ",
    "                              ",
    "                              ",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "Xooooooooooooooooooooooooooo X",
    "X XXXXXXXX XXXXXXXX XXXXXXXX X",
    "X X      X X      X X      X X",
    "X XXXXXXXX XXXXXXXX XXXXXXXX X",
    "Xooooooooooooooooooooooooooo X",
    "X XXX XXXXXXXX  XXXXXXXX XXX X",
    "X X X X      X  X      X X X X",
    "X X X XXXXXXXX  XXXXXXXX X X X",
    "X X X                    X X X",
    "X X X XXXXXXXX  XXXXXXXX X X X",
    "X XXX                    XXX X",
    "X oooooooooooooooooooooooooo X",
    "X XXXXXXXX XXXXXXXX XXXXXXXX X",
    "X X      X X      X X      X X",
    "X XXXXXXXX XXXXXXXX XXXXXXXX X",
    "Xooooooooooooooooooooooooooo X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",

};

void dibujar_mapa(){
    int filas_m1, col_m1;
    for (filas_m1=0; filas_m1< Filas; filas_m1++){
        for(col_m1=0; col_m1<Columnas; col_m1++){
            if (mapa_1[filas_m1][col_m1]=='X')
                draw_sprite(escenario,roca,col_m1*30,filas_m1*30);
            else if (mapa_1[filas_m1][col_m1]=='o'){
                draw_sprite(escenario,coin,col_m1*30,filas_m1*30);
                if(pacman1.posY/30 ==filas_m1 && pacman1.posX/30==col_m1)
                    mapa_1[filas_m1][col_m1]= ' ';
            }
        }
    }
}



void pantalla(){
    blit(escenario, screen, 0,0,0,0,900,700);
}

void dibujarpersonaje(){
    blit(pacman_mb, pacman, pacman1.direccion*30,0,0,0,30,30);
    draw_sprite(escenario, pacman, pacman1.posY, pacman1.posX);

}


int main()
{
    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,630,0,0);

    escenario = create_bitmap (900,680);
    roca= load_bitmap("roca.bmp",NULL);

    pacman_mb = load_bitmap("pacman.bmp",NULL);
    pacman = create_bitmap(30,30);
    enemigo = create_bitmap (30,30);
    enemigo_mb = load_bitmap("enemigo.bmp",NULL);
    coin = load_bitmap("coin.bmp",NULL);
    muerte = muerte("muerte.bmp",NULL);


    while(!key[KEY_ESC]){

        if (key[KEY_LEFT]) pacman1.direccion=2;
        else if (key[KEY_RIGHT]) pacman1.direccion=0;
        else if (key[KEY_UP]) pacman1.direccion=4;
        else if (key[KEY_DOWN]) pacman1.direccion=3;

        if(pacman1.direccion==0) {
            if (mapa_1[pacman1.posY/30][(pacman1.posX+30)/30] != 'X')
                pacman1.posX +=30;
            else
                pacman1.direccion=1;
        }
        if(pacman1.direccion==2) {
            if (mapa_1[pacman1.posY/30][(pacman1.posY-30)/30] != 'X')
                pacman1.posX -=30;
            else
                pacman1.direccion=1;
            }
        if (pacman1.direccion==4) {
            if (mapa_1[(pacman1.posY-30)/30][pacman1.posX/30]!= 'X')
                pacman1.posY -=30;
            else
                pacman1.direccion=1;
                }
        if(pacman1.direccion==3) {
             if (mapa_1[(pacman1.posY+30)/30][pacman1.posY/30]!= 'X')
                pacman1.posY +=30;
            else
                pacman1.direccion=1;
        }

        clear(escenario);

        dibujar_mapa();
        dibujarpersonaje();
        fantasma();
        pantalla();
        rest(90);

        clear(pacman);
        blit(pacman_mb,pacman, 1*30,0,0,0,30,30);
        draw_sprite(escenario, pacman, pacman1.posX,pacman1.posY);
        pantalla();
        rest(90);
    }
    return 0;
    return 0;
}
END_OF_MAIN();
