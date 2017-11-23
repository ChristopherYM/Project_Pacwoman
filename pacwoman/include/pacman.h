#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidad.h"


class personaje : public entidad
{
    public:

        void setPosicion(int x, int y){
            posX=x;
            posY=y;
        }

};

#endif // PACMAN_H
