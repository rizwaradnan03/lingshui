#include <constants/ct_shader.h>

namespace constant_shader {

    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        uniform vec2 uPos; // OBJECT POSITION
        
        void main() {
            gl_Position = vec4(aPos.xy + uPos, aPos.z, 1.0);
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