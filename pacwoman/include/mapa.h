#ifndef MAPA_H
#define MAPA_H
#include <stdlib.h>

class mapa
{
    public:
        int filas, columnas;
        char **mapa_;

        mapa(int x, int y){
        filas=x;
        columnas=y;

        }

        void crearMapa1(){
        mapa_ = new char *[filas];
        for (int i=0; i<filas;i++)
            mapa_[i]=new char[columnas];


        }

};

#endif // MAPA_H
