#include <allegro.h>
#include <cstdlib>

#define Filas 21
#define Columnas 31

BITMAP *buffer;
BITMAP *roca;
BITMAP *pacbmp;
BITMAP *pacman;


int dir;
int px=30*10, py=30*10;

char mapa_1[Filas][Columnas] = {
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X                           X",
    "X                           X",
    "X       X          X        X",
    "X                           X",
    "X                           X",
    "X                           X",
    "X                           X",
    "X    X                 X    X",
    "X     X               X     X",
    "X      XXXXXXXXXXXXXXX      X",
    "X                           X",
    "X                           X",
    "X                           X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

void dibujar_mapa(){
    int row, col;
    for (row=0; row< Filas; row++){
        for(col=0; col<Columnas; col++){
            if (mapa_1[row][col]=='X')
                draw_sprite(buffer,roca,col*30,row*30);
        }
    }
}



void pantalla(){
    blit(buffer, screen, 0,0,0,0,900,700);
}

void dibujarpersonaje(){
    blit(pacbmp, pacman, dir*30,0,0,0,30,30);
    draw_sprite(buffer, pacman, px, py);

}

int main()
{
    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,630,0,0);

    buffer = create_bitmap (900,680);
    roca= load_bitmap("roca.bmp",NULL);

    pacbmp = load_bitmap("pacman.bmp",NULL);
    pacman = create_bitmap(30,30);

    while(!key[KEY_ESC]){
        if (key[KEY_LEFT]) dir=2;
        else if (key[KEY_RIGHT]) dir=0;
        else if (key[KEY_UP]) dir=4;
        else if (key[KEY_DOWN]) dir=3;

        if(dir==0) {
            if (mapa_1[py/30][(px+30)/30] != 'X')
                px +=30;
            else
                dir=1;
        }
        if(dir==2) {
            if (mapa_1[py/30][(px-30)/30] != 'X')
                px -=30;
            else
                dir=1;
            }
        if (dir==4) {
            if (mapa_1[(py-30)/30][px/30]!= 'X')
                py -=30;
            else
                dir=1;
                }
        if(dir==3) {
             if (mapa_1[(py+30)/30][px/30]!= 'X')
                py +=30;
            else
                dir=1;
        }

        clear(buffer);

        dibujar_mapa();
        dibujarpersonaje();
        pantalla();
        rest(90);

        clear(pacman);
        blit(pacbmp,pacman, 1*30,0,0,0,30,30);
        draw_sprite(buffer, pacman, px,py);
        pantalla();
        rest(90);
    }
    return 0;
}
END_OF_MAIN();
