#include <singleton/st_gl.h>

SINGLETON_C_gl* G_C_gl = nullptr;

SINGLETON_C_gl::SINGLETON_C_gl(){}

GLFWwindow* SINGLETON_C_gl::get_window(){
    return this->window;
}

void SINGLETON_C_gl::set_window(GLFWwindow* value){
    this->window = value;
}

int SINGLETON_C_gl::get_current_width(){
    return this->current_width;
}

void SINGLETON_C_gl::set_current_width(int value){
    this->current_width = value;
}

int SINGLETON_C_gl::get_current_height(){
    return this->current_height;
}

void SINGLETON_C_gl::set_current_height(int value){
    this->current_height = value;
}

bool SINGLETON_C_gl::get_initialize(){
    return this->initialize;
}

void SINGLETON_C_gl::set_initialize(bool value){
    this->initialize = value;
}

bool SINGLETON_C_gl::get_resized(){
    return this->resized;
}

void SINGLETON_C_gl::set_resized(bool value){
    this->resized = value;
}