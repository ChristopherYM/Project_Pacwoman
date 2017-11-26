#ifndef CLASEALLEGRO_H
#define CLASEALLEGRO_H
#include <allegro.h>
#include <cstdlib>
#include "escenario.h"



class claseallegro
{

    public:
        claseallegro(){
            allegro_init();
            install_keyboard();
            set_color_depth(32);
            set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,510,0,0);
        }

        void pantalla(escenario escenario1){
            blit(escenario1.escenario_, screen, 0,0,0,0,1200,510);
        }


};

#endif // CLASEALLEGRO_H
