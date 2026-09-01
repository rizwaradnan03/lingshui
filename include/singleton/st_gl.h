#ifndef SINGLETON_GL_H
#define SINGLETON_GL_H

#include <config/c_pch.h>

class SINGLETON_C_gl {
    public:
        SINGLETON_C_gl();

        GLFWwindow* get_window();
        void set_window(GLFWwindow* value);
        
    private:
        GLFWwindow* window = nullptr;
        
        int default_width = 800;
        int default_height = 600;
};

extern SINGLETON_C_gl* G_C_gl;

#endif