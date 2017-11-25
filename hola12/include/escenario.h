#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <allegro.h>
#define Filas 21
#define Columnas 31
using namespace std;

class escenario
{
    public:
        BITMAP *escenario_;
        BITMAP *roca;
        BITMAP *coin;

        char mapa_1[Filas][Columnas]={
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                "Xooooooooooooooooooooooooooo X",
                "X XXXXXXXXXXXXXXXXXXXXXXXXXX X",
                "X XXXXXXXXXXXXXXXXXXXXXXXXXX X",
                "Xooooooooooooooooooooooooooo X",
                "X XXXXXXXX XXXXXXXX XXXXXXXX X",
                "X X      X X      X X      X X",
                "X XXXXXXXX XXXXXXXX XXXXXXXX X",
                "Xooooooooooooooooooooooooooo X",
                "X XXX XXXXXXXX  XXXXXXXX XXX X",
                "X X X X      X  X      X X X X",
                "  X X XXXXXXXX  XXXXXXXX X X  ",
                "X X X                    X X X",
                "X X X XXXXXXXX  XXXXXXXX X X X",
                "X XXX                    XXX X",
                "X oooooooooooooooooooooooooo X",
                "X XXXXXXXX XXXXXXXX XXXXXXXX X",
                "X X      X X      X X      X X",
                "X XXXXXXXX XXXXXXXX XXXXXXXX X",
                "Xooooooooooooooooooooooooooo X",
                "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",};

        escenario(){
        escenario_ = create_bitmap (900,630);
        roca= load_bitmap("roca.bmp",NULL);
        coin = load_bitmap("coin.bmp",NULL);
        }

        void dibujar_mapa(){
            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< Filas; filas_m1++){
                for(col_m1=0; col_m1<Columnas; col_m1++){
                    if (mapa_1[filas_m1][col_m1]=='X')
                        draw_sprite(escenario_,roca,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='o'){
                        draw_sprite(escenario_,coin,col_m1*30,filas_m1*30);

                    }
                }
        }
}

};

#endif // ESCENARIO_H
