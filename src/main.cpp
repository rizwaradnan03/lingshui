#include "config/c_pch.h"
#include <singleton/st_gl.h>
#include <signature/s_mesh.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void GL_init(){
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW!" << std::endl;
    }
}

void GL_window(){
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
}

void openGL(){
    GL_init();

    SYSTEM_init();
    
    GL_window();
    GL_gpu();
}

int main() {
    openGL();

    GLFWwindow* win = G_C_gl->get_window();

    DtoSubMesh sb_mesh;
    sb_mesh.raw_vertices = std::vector<GLfloat>({
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f
    });
    
    DtoInitSignatureMesh sg_mesh;
    sg_mesh.mesh = sb_mesh;

    SIGNATURE_mesh *obj = new SIGNATURE_mesh(sg_mesh);
    
    while (!glfwWindowShouldClose(win)) {
        // Input Handling
        if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(win, true);
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // THE WRITING!
        obj->execute();
        
        // Swap Buffers & Poll Events
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}