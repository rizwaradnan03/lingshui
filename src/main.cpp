#include "config/c_pch.h"
#include <singleton/st_gl.h>
#include <iostream>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

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
    
    GLfloat vertices[] =
   	{
  		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
  		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
  		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
   	};
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // STICK
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader); // COMPILE INTO THE MACHINE CODE THAT GPU COULD UNDERSTAND

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram(); // THE EXECUTOR!
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO); // DEFAULT CONFIGURATION OF GPU THAT WILL BE CONTAINED VBO AND EBO
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // LINK THE VERTICES INTO VBO!

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    while (!glfwWindowShouldClose(win)) {
        // Input Handling
        if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(win, true);
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // THE WRITING!
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // Swap Buffers & Poll Events
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}