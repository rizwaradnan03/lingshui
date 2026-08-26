#ifndef SINGLETON_SYSTEM_H
#define SINGLETON_SYSTEM_H

#include <dto/dto_s_system.h>
#include <nodes/2d/render-type/render_type.h>

class RT_world;

class SINGLETON_system {
    public:
        SINGLETON_system();
        ~SINGLETON_system();

        RenderType* get_render_screen();
        void set_render_screen(RenderType* value);

        void change_screen(EnumSystemChangeScreen value);
        
    private:
        RenderType* render_screen;
};

extern SINGLETON_system *G_S_system;

#endif