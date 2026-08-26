#include <singleton/st_system.h>
#include <nodes/2d/render-type/rt_world.h>

SINGLETON_system *G_S_system = nullptr;

SINGLETON_system::SINGLETON_system(){}

SINGLETON_system::~SINGLETON_system(){
    delete this->get_render_screen();
}

RenderType* SINGLETON_system::get_render_screen(){
    return this->render_screen;
}

void SINGLETON_system::set_render_screen(RenderType* value){
    this->render_screen = value;
}

void SINGLETON_system::change_screen(EnumSystemChangeScreen value){
    RenderType* rt = nullptr;
    if(value == WORLD_TRIAL){
        rt = new RT_world();
    }
    
    this->set_render_screen(rt);
}