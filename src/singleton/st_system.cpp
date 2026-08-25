#include <singleton/st_system.h>

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