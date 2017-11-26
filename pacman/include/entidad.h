#ifndef ENTIDAD_H
#define ENTIDAD_H


class entidad
{
    public:
        int direccion;
        int posX, posY;

        virtual void setPosicion(int x, int y)= 0  ;


};

#endif // ENTIDAD_H
