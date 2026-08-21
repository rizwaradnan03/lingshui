#include <singleton/st_gl.h>

SINGLETON_C_gl* G_C_gl = nullptr;

SINGLETON_C_gl::SINGLETON_C_gl(){}

GLFWwindow* SINGLETON_C_gl::get_window(){
    return this->window;
}

void SINGLETON_C_gl::set_window(GLFWwindow* value){
    this->window = value;
}