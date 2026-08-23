#include <constants/ct_shader.h>

namespace constant_shader {

    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        uniform vec4 objectColor;
        
        void main() {
            FragColor = objectColor;
        }
    )";

}