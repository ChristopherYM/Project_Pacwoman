#include <allegro.h>
#include <cstdlib>

#define Filas 21
#define Columnas 31

BITMAP *buffer;
BITMAP *roca;
BITMAP *pacbmp;
BITMAP *pacman;
BITMAP *enemigobmp;
BITMAP *enemigo;


int dir;
int px=30*10, py=30*10;
int fdir;
int _x=30*14 , _y=30*13;

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

void dibujar_fantasma(){
    blit(enemigobmp, enemigo,0,0,0,0,30,30);
    draw_sprite(buffer, enemigo, _x, _y);
}

void fantasma(){
    dibujar_fantasma();
    if (fdir==0){
        if(mapa_1[_y/30][(_x-30)/30] != 'X')
            _x-=30;
        else
            fdir = rand()%3;
    }
    if (fdir==1){
        if(mapa_1[_y/30][(_x+30)/30]!= 'X')
            _x+=30;
        else
            fdir = rand()%3;
    }
    if (fdir==2){
        if(mapa_1[(_y-30)/30][(_x)/30]!= 'X')
            _y-=30;
        else
            fdir = rand()%3;
    }
    if (fdir==3){
        if(mapa_1[(_y+30)/30][(_x)/30]!= 'X')
            _y+=30;
        else
            fdir = rand()%3;
        }
    if(_x<=-30)
        _x=870;
    else if (_x>=870)
        _x=-30;
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
    enemigo = create_bitmap (30,30);
    enemigobmp = load_bitmap("enemigo.bmp",NULL);

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
        fantasma();
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
