#ifndef ENEMIGO_H
#define ENEMIGO_H
#inclide <entidad.h>

class enemigo : public entidad
{
    public:
        BITMAP *enemigob_mb;
        BITMAP *enemigo;
        int posX, posY;


        enemigo(){
            posX=0;
            posY=0;
            enemigo = create_bitmap (30,30);
            enemigo_mb = load_bitmap("enemigo.bmp",NULL);}

        void setPosicion(int x, int y){
            posX=x;
            posY=y;}

         void dibujar_fantasma(enemigo enemigo1){
            blit(enemigo_mb, enemigo,0,0,0,0,30,30);
            draw_sprite(escenario.escenario, enemigo, enemigo1.posX, enemigo1.posY);}

        void choqueFantasma(personaje pacman1, enemigo enemigo1){
            if ((pacman1.posY == enemigo1.posY && pacman1.posX == enemigo1.posX)|| (enemigo1.posY==(pacman1.posY-30) && enemigo1.posX ==(pacman1.posX-30))){
                for (int j=0; j<=5; j++){
                    clear(pacman);
                    clear(escenario);
                    dibujar_mapa();
                        blit(muerte,pacman,j*30,0,0,0,30,30);
                        draw_sprite(muerte,pacman,pacman1.posX, pacman1.posY);
                        pantalla();
                        rest(90);}
                pacman1.posX=30*10;
                pacman1.posY=30*12;
                pacman1.direccion=4;}}

        void fantasma(enemigo enemigo1){
            dibujar_fantasma();
            if (enemigo1.direccion==0){
                if(mapa_1[enemigo1.posY/30][(enemigo1.posX-30)/30] != 'X')
                    enemigo1.posX-=30;
                else
                    enemigo1.direccion = rand()%3;}
            if (enemigo1.direccion==1){
                if(mapa_1[enemigo1.posY/30][(enemigo1.posX+30)/30]!= 'X')
                    enemigo1.posX+=30;
                else
                    enemigo1.direccion = rand()%3;}
            if (enemigo1.direccion==2){
                if(mapa_1[(enemigo1.posY-30)/30][(enemigo1.posX)/30]!= 'X')
                    enemigo1.posY-=30;
                else
                    enemigo1.direccion = rand()%3;}
            if (enemigo1.direccion==3){
                if(mapa_1[(enemigo1.posY+30)/30][(enemigo1.posX)/30]!= 'X')
                    enemigo1.posY+=30;
                else
                    enemigo1.direccion = rand()%3;}
            if(enemigo1.posX<=-30)
                enemigo1.posX=870;
            else if (enemigo1.posX>=870)
                enemigo1.posX=-30;}

};

#endif // ENEMIGO_H
