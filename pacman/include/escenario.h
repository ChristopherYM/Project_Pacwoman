#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <allegro.h>


#define Filas 17
#define Columnas 40
using namespace std;

class escenario
{
    public:
        BITMAP *escenario_;
        BITMAP *roca;
        BITMAP *roca1;
        BITMAP *roca2;
        BITMAP *roca3;
        BITMAP *roca4;
        BITMAP *roca5;
        BITMAP *roca6;
        BITMAP *roca7;
        BITMAP *roca8;
        BITMAP *roca9;
        BITMAP *roca10;
        BITMAP *roca11;
        BITMAP *roca12;
        BITMAP *roca13;
        BITMAP *roca14;
        BITMAP *roca15;
        BITMAP *roca16;
        BITMAP *roca17;
        BITMAP *roca18;
        BITMAP *roca19;


        char mapa_1[Filas][Columnas]={
                "              NoN     NoN              ",
                " AZZZZZZZZZZZSVoV     VoVAZZZZZZZZZZZS ",
                " VoooooooooooVVoV     VoVVoooooooooooV ",
                " VoXZZCoXZZCoMDoMZZZZZDoMDoXZZCoXZZCoV ",
                " VoooooooooooooooooooooooooooooooooooV ",
                " VoXZZSoXZZZZZCoXZCoXZCoXZZZZZCoAZZCoV ",
                " VooooVoooooooooooooooooooooooooVooooV ",
                "XFZZCoBoXZZZCoNoWL   LE NoXZZZCoBoXZZFC",
                "ooooooooooooooVoH     JoVoooooooooooooo",
                "XGZZCoNoXZZZCoBoQKKKKKR BoXZZZCoNoXZZGC",
                " VooooVoooooooooooooooooooooooooVooooV ",
                " VoXZZDoXZZZZZCoXZCoXZCoXZZZZZCoMZZCoV ",
                " Vooooooooooooooooo oooooooooooooooooV ",
                " VoXZZCoXZZCoASoAZZZZZSoASoXZZCoXZZCoV ",
                " VoooooooooooVVoV     VoVVoooooooooooV ",
                " MZZZZZZZZZZZDVoV     VoVMZZZZZZZZZZZD ",
                "              BoB     BoB              ",};
        char mapa_2[Filas][Columnas]={
                "              NoN     NoN              ",
                " AZZZZZZZZZZZSVoV     VoVAZZZZZZZZZZZS ",
                " V           VVoV     VoVV           V ",
                " V XZZC XZZC MDoMZZZZZDoMD XZZC XZZC V ",
                " V                                   V ",
                " V XZZC AZZS N   N AZGZGZS AZZS XZZC V ",//
                " V      V  V V   V V V V V V  V      V ",
                "XFZZCoN V  V V   V V V V V V  V NoXZZFC",
                "ooooooV VZZV VZZZV V V V V VZZV V ooooo",
                "XGZZCoB V  V V   V V V V V V  V BoXZZGC",
                " V      V  V V   V V V V V V  V      V ",
                " VoXZZCoB  B B   B B B B B B  B XZZC V ",//
                " V                                   V ",
                " VoXZZCoXZZCoASoAZZZZZSoASoXZZCoXZZCoV ",
                " VoooooooooooVVoV     VoVVoooooooooooV ",
                " MZZZZZZZZZZZDVoV     VoVMZZZZZZZZZZZD ",
                "              BoB     BoB              ",};

        escenario(){
        escenario_ = create_bitmap (1200 ,510);
        roca= load_bitmap("roca.bmp",NULL);
        roca1=load_bitmap("roca1.bmp",NULL);
        roca2=load_bitmap("roca2.bmp",NULL);
        roca3=load_bitmap("roca3.bmp",NULL);
        roca4=load_bitmap("roca4.bmp",NULL);
        roca5=load_bitmap("roca5.bmp",NULL);
        roca6=load_bitmap("roca6.bmp",NULL);
        roca7=load_bitmap("roca7.bmp",NULL);
        roca8=load_bitmap("roca8.bmp",NULL);
        roca9=load_bitmap("roca9.bmp",NULL);
        roca10=load_bitmap("roca10.bmp",NULL);
        roca11=load_bitmap("roca11.bmp",NULL);
        roca12=load_bitmap("roca12.bmp",NULL);
        roca13=load_bitmap("roca13.bmp",NULL);
        roca14=load_bitmap("roca14.bmp",NULL);
        roca15=load_bitmap("roca15.bmp",NULL);
        roca16=load_bitmap("roca16.bmp",NULL);
        roca17=load_bitmap("roca17.bmp",NULL);
        roca18=load_bitmap("roca18.bmp",NULL);
        roca19=load_bitmap("roca19.bmp",NULL);
        }

        void dibujar_mapa(){
            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< Filas; filas_m1++){
                for(col_m1=0; col_m1<Columnas; col_m1++){
                    if (mapa_1[filas_m1][col_m1]=='X')
                        draw_sprite(escenario_,roca,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='Z')
                        draw_sprite(escenario_,roca1,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='C')
                        draw_sprite(escenario_,roca2,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='V')
                        draw_sprite(escenario_,roca3,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='B')
                        draw_sprite(escenario_,roca4,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='N')
                        draw_sprite(escenario_,roca5,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='M')
                        draw_sprite(escenario_,roca6,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='A')
                        draw_sprite(escenario_,roca7,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='S')
                        draw_sprite(escenario_,roca8,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='D')
                        draw_sprite(escenario_,roca9,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='F')
                        draw_sprite(escenario_,roca10,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='G')
                        draw_sprite(escenario_,roca11,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='H')
                        draw_sprite(escenario_,roca12,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='J')
                        draw_sprite(escenario_,roca13,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='K')
                        draw_sprite(escenario_,roca14,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='L')
                        draw_sprite(escenario_,roca15,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='Q')
                        draw_sprite(escenario_,roca16,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='W')
                        draw_sprite(escenario_,roca17,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='E')
                        draw_sprite(escenario_,roca18,col_m1*30,filas_m1*30);
                    else if (mapa_1[filas_m1][col_m1]=='R')
                        draw_sprite(escenario_,roca19,col_m1*30,filas_m1*30);
                    }}}

        void dibujar_mapa2(){
            int filas_m1, col_m1;
            for (filas_m1=0; filas_m1< Filas; filas_m1++){
                for(col_m1=0; col_m1<Columnas; col_m1++){
                    if (mapa_2[filas_m1][col_m1]=='X')
                        draw_sprite(escenario_,roca,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='Z')
                        draw_sprite(escenario_,roca1,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='C')
                        draw_sprite(escenario_,roca2,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='V')
                        draw_sprite(escenario_,roca3,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='B')
                        draw_sprite(escenario_,roca4,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='N')
                        draw_sprite(escenario_,roca5,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='M')
                        draw_sprite(escenario_,roca6,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='A')
                        draw_sprite(escenario_,roca7,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='S')
                        draw_sprite(escenario_,roca8,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='D')
                        draw_sprite(escenario_,roca9,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='F')
                        draw_sprite(escenario_,roca10,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='G')
                        draw_sprite(escenario_,roca11,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='H')
                        draw_sprite(escenario_,roca12,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='J')
                        draw_sprite(escenario_,roca13,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='K')
                        draw_sprite(escenario_,roca14,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='L')
                        draw_sprite(escenario_,roca15,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='Q')
                        draw_sprite(escenario_,roca16,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='W')
                        draw_sprite(escenario_,roca17,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='E')
                        draw_sprite(escenario_,roca18,col_m1*30,filas_m1*30);
                    else if (mapa_2[filas_m1][col_m1]=='R')
                        draw_sprite(escenario_,roca19,col_m1*30,filas_m1*30);
                    }}}




};

#endif // ESCENARIO_H
