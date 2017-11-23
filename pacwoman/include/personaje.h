#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"


class personaje : public entidad
{
    public:
        personaje(){
        posX = 0;
        posY = 0;
        direccion = 4;}

        void setPosicion(int x, int y){
            posX=x;
            posY=y;
        }

};


#endif // PERSONAJE_H
