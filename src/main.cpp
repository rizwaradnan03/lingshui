#include "config/c_pch.h"
#include <singleton/st_gl.h>
#include <singleton/st_system.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void GL_init(){
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW!" << std::endl;
    }
}

void GL_window(){
    glfwWindowHintString(GLFW_WAYLAND_APP_ID, "my_opengl_app");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    G_C_gl->set_window(glfwCreateWindow(800, 600, "Lingshui", NULL, NULL));
    GLFWwindow* win = G_C_gl->get_window();
    
    if (win == NULL) {
        std::cerr << "Gagal membuat Window GLFW!" << std::endl;
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(win);
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
}

void GL_gpu(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Gagal menginisialisasi GLAD!" << std::endl;
    }
}

void SYSTEM_init(){
    G_C_gl = new SINGLETON_C_gl();
    G_S_system = new SINGLETON_system();
}

void SYSTEM_start(){
    G_S_system->change_screen(WORLD_TRIAL);
}

void openGL(){
    GL_init();

    SYSTEM_init();
    
    GL_window();
    GL_gpu();

    SYSTEM_start();
}

int main() {
    openGL();

    GLFWwindow* win = G_C_gl->get_window();
    
    while (!glfwWindowShouldClose(win)) {
        // Input Handling
        if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(win, true);
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // THE WRITING SECTION HERE!
        G_S_system->get_render_screen()->execute();
        
        // Swap Buffers & Poll Events
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}