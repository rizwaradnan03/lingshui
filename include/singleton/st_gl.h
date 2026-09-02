#ifndef SINGLETON_GL_H
#define SINGLETON_GL_H

#include <config/c_pch.h>

class SINGLETON_C_gl {
    public:
        SINGLETON_C_gl();

        GLFWwindow* get_window();
        void set_window(GLFWwindow* value);

        int get_current_width();
        void set_current_width(int value);

        int get_current_height();
        void set_current_height(int value);

        bool get_initialize();
        void set_initialize(bool value);

        bool get_resized();
        void set_resized(bool value);
        
    private:
        GLFWwindow* window = nullptr;
        int current_width;
        int current_height;

        bool initialize = false;
        bool resized = false;
};

extern SINGLETON_C_gl *G_C_gl;

#endif