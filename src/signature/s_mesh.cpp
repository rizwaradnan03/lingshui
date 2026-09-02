#include "constants/ct_default.h"
#include "singleton/st_gl.h"
#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(const DtoSubMesh& init){
    this->set_mesh(init);
    DtoSubMesh& m = this->get_mesh();

    this->set_w_pixel(static_cast<float>(m.w / dft::get_window_width()));
    this->set_h_pixel(static_cast<float>(m.h / dft::get_window_height()));
    
    float w_half = (init.w / 2.0f);
    float h_half = init.h / 2.0f;

    this->calculate_count_of_attribute();

    uint8_t x_exist = m.v_size / 2;
    uint8_t y_exist = m.v_size / 2;
    for(uint16_t i = 0; i < m.v_size; i++){
        float val;
        if((i + 2) % 2 == 0){
            if(x_exist == m.v_size / 2 || (x_exist != m.v_size / 2 && x_exist < (m.v_size / 2) / 2)){ 
                val = m.x - w_half;
            }else{
                val = m.x + w_half;
            }
            x_exist -= 1;
        }else{
            if(y_exist > (m.v_size / 2) / 2){
                val = m.y - h_half;
            }else{
                val = m.y + h_half;
            }
            y_exist -= 1;
        }

        m.vertices[i] = val;
    }

    this->calculate_ebo();
    this->init_shader_buffer();
    this->process_VAO();
    this->process_VBO();
    this->process_EBO();

    this->gpu_base_smart();
}

SIGNATURE_mesh::~SIGNATURE_mesh(){
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);

    DtoSubMesh& m = this->get_mesh();
    glDeleteProgram(m.shaderProgram);
}

GLuint SIGNATURE_mesh::get_VAO(){ return this->VAO; }
void SIGNATURE_mesh::set_VAO(GLuint value){ this->VAO = value; }

void SIGNATURE_mesh::process_VAO(){
    GLuint v;
    glGenVertexArrays(1, &v);
    this->set_VAO(v);
    glBindVertexArray(this->get_VAO());
}

GLuint SIGNATURE_mesh::get_VBO(){ return this->VBO; }
void SIGNATURE_mesh::set_VBO(GLuint value){ this->VBO = value; }

void SIGNATURE_mesh::process_VBO(){
    DtoSubMesh& m = this->get_mesh();

    if(this->get_VBO() == 0){
        glGenBuffers(1, &this->VBO);
    }

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, m.v_size * sizeof(float), m.vertices, GL_STATIC_DRAW);
}

GLuint SIGNATURE_mesh::get_EBO(){ return this->EBO; }
void SIGNATURE_mesh::set_EBO(GLuint value){ this->EBO = value; }

void SIGNATURE_mesh::process_EBO(){
    DtoSubMesh& m = this->get_mesh();

    if(this->get_EBO() == 0){
        glGenBuffers(1, &this->EBO);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m.i_size * sizeof(uint8_t), m.indices, GL_STATIC_DRAW);
}

float SIGNATURE_mesh::get_x(){ return this->get_mesh().x; }
void SIGNATURE_mesh::set_x(float value){ this->get_mesh().x = value; }
float SIGNATURE_mesh::get_y(){ return this->get_mesh().y; }
void SIGNATURE_mesh::set_y(float value){ this->get_mesh().y = value; }
float SIGNATURE_mesh::get_w(){ return this->get_mesh().w; }
void SIGNATURE_mesh::set_w(float value){ this->get_mesh().w = value; }
float SIGNATURE_mesh::get_h(){ return this->get_mesh().h; }
void SIGNATURE_mesh::set_h(float value){ this->get_mesh().h = value; }

DtoGlobalPole& SIGNATURE_mesh::get_pole(){ return this->get_mesh().pole; }
void SIGNATURE_mesh::set_pole(DtoGlobalPole value){ this->get_mesh().pole = value; }

uint8_t SIGNATURE_mesh::get_v_size(){ return this->get_mesh().v_size; }
void SIGNATURE_mesh::set_v_size(uint8_t value){ this->get_mesh().v_size = value; }
uint8_t SIGNATURE_mesh::get_i_size(){ return this->get_mesh().i_size; }
void SIGNATURE_mesh::set_i_size(uint8_t value){ this->get_mesh().i_size = value; }

float SIGNATURE_mesh::get_w_pixel(){
    return this->get_mesh().w_pixel;
}

void SIGNATURE_mesh::set_w_pixel(float value){
    this->get_mesh().w_pixel = value;
}

float SIGNATURE_mesh::get_h_pixel(){
    return this->get_mesh().h_pixel;
}

void SIGNATURE_mesh::set_h_pixel(float value){
    this->get_mesh().h_pixel = value;
}

float SIGNATURE_mesh::get_top(){ return this->get_y() + (this->get_h() / 2); }
float SIGNATURE_mesh::get_bottom(){ return this->get_y() - (this->get_h() / 2); }
float SIGNATURE_mesh::get_right(){ return this->get_x() + (this->get_w() / 2); }
float SIGNATURE_mesh::get_left(){ return this->get_x() - (this->get_w() / 2); }

DtoSubMesh& SIGNATURE_mesh::get_mesh(){ return this->mesh; }
void SIGNATURE_mesh::set_mesh(DtoSubMesh value){ this->mesh = value; }

void SIGNATURE_mesh::init_shader_buffer(){
    DtoSubMesh& m = this->get_mesh();

    GLint success;
    char log[512];

    m.vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m.vertexShader, 1, &constant_shader::vertexShaderSource, NULL);
    glCompileShader(m.vertexShader);

    glGetShaderiv(m.vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(m.vertexShader, 512, NULL, log);
        std::cout << "VERTEX SHADER ERROR : " << log << std::endl;
    }

    m.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m.fragmentShader, 1, &constant_shader::fragmentShaderSource, NULL);
    glCompileShader(m.fragmentShader);

    glGetShaderiv(m.fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(m.fragmentShader, 512, NULL, log);
        std::cout << "FRAGMENT SHADER ERROR : " << log << std::endl;
    }

    m.shaderProgram = glCreateProgram();
    glAttachShader(m.shaderProgram, m.vertexShader);
    glAttachShader(m.shaderProgram, m.fragmentShader);
    glLinkProgram(m.shaderProgram);

    glDeleteShader(m.vertexShader);
    glDeleteShader(m.fragmentShader);
}

void SIGNATURE_mesh::calculate_ebo(){
    DtoSubMesh& m = this->get_mesh();

    uint8_t dec_by = 0;
    for(uint8_t i = 0; i < m.i_size; i++){
        if(i % 3 == 0){
            dec_by = i / 3;
        }else{
            if(i == m.i_size - 1){
                dec_by = i;
            }
        }

        m.indices[i] = i - dec_by;
    }
}

// Perhitungan atribut asli kamu
void SIGNATURE_mesh::calculate_count_of_attribute(){
    DtoSubMesh& m = this->get_mesh();

    m.v_size = shape::get_vertice_value_from_shape(m.shape) * 2;
    m.i_size = (m.v_size / 2) + ((m.v_size / 2) / 2);
}

void SIGNATURE_mesh::gpu_base_smart(){
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void SIGNATURE_mesh::color_draw(){
    DtoSubMesh& m = this->get_mesh();
    
    if (m.color.size() < 4) {
        m.color = {1.0f, 1.0f, 1.0f, 1.0f};
    }

    int c_loc = glGetUniformLocation(m.shaderProgram, "objectColor");
    glUniform4f(c_loc, m.color[0], m.color[1], m.color[2], m.color[3]);
}

void SIGNATURE_mesh::change_axist(DtoEnumAxist axist, float value){
    DtoSubMesh& m = this->get_mesh();

    uint8_t div_by = 1;
    if(axist == X){
        div_by = 0;
    }

    for(uint8_t i = 0; i < m.v_size; i++){
        if((i + 2) % 2 == div_by){
            m.vertices[i] += value;
        }
    }

    this->process_VBO();
}

void SIGNATURE_mesh::execute(){
    this->display();
}

void SIGNATURE_mesh::display(){
    this->buffer_checker();
    
    DtoSubMesh& m = this->get_mesh();

    glUseProgram(m.shaderProgram);
    this->color_draw();

    glBindVertexArray(this->get_VAO());

    glDrawElements(GL_TRIANGLES, m.i_size, GL_UNSIGNED_BYTE, 0);

    glBindVertexArray(0);
}

void SIGNATURE_mesh::buffer_checker(){
    SINGLETON_C_gl *gl = G_C_gl;
    
    bool resize = gl->get_resized();
    if(resize == false){
        return;
    }
    
    DtoSubMesh& value = this->get_mesh();
    
    uint16_t w_gap = ((dft::get_window_width() - gl->get_current_width()) * value.w_pixel) * -1;
    uint16_t h_gap = ((dft::get_window_height() - gl->get_current_height()) * value.h_pixel) * -1;
    
    this->set_w(this->get_w() + w_gap);
    this->set_h(this->get_h() + h_gap);
}