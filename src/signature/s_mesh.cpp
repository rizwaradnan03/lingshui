#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(const DtoSubMesh& init){
    this->set_mesh(init);
    
    float w_half = init.w / 2;
    float h_half = init.h / 2;    

    this->calculate_count_of_attribute();

    DtoSubMesh& m = this->get_mesh();
    
    uint8_t x_exist = m.v_size / 2;
    uint8_t y_exist = m.v_size / 2;
    for(uint16_t i = 0;i < m.v_size;i++){
        float val;
        if((i + 2) % 2 == 0){
            if(x_exist == m.v_size / 2 || (x_exist != m.v_size / 2 && x_exist < (m.v_size / 2) / 2)){ // be the negative
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

    for(uint8_t i = 0;i < m.v_size;i++){
        std::cout << "VERT : " << m.vertices[i] << std::endl;
    }

    for(uint8_t i = 0;i < m.i_size;i++){
        std::cout << "INDICES : " << static_cast<int>(m.indices[i]) << std::endl;
    }
    
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

GLuint SIGNATURE_mesh::get_VAO(){
    return this->VAO;
}

void SIGNATURE_mesh::set_VAO(GLuint value){
    this->VAO = value;
}

void SIGNATURE_mesh::process_VAO(){
    GLuint v;
    glGenVertexArrays(1, &v);
    this->set_VAO(v);
    
    glBindVertexArray(this->get_VAO());
}

GLuint SIGNATURE_mesh::get_VBO(){
    return this->VBO;
}

void SIGNATURE_mesh::set_VBO(GLuint value){
    this->VBO = value;
}

void SIGNATURE_mesh::process_VBO(){
    DtoSubMesh& m = this->get_mesh();

    if(this->get_VBO() == 0){ // CREATE BUFFER FOR THE FIRST TIME
        glGenBuffers(1, &this->VBO);
    }

    // CALL BUFFER TO USE THE VERTICES VALUE
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, m.v_size * sizeof(float), m.vertices, GL_STATIC_DRAW);
}

DtoSubMesh& SIGNATURE_mesh::get_mesh(){
    return this->mesh;
}

void SIGNATURE_mesh::set_mesh(DtoSubMesh value){
    this->mesh = value;
}

GLuint SIGNATURE_mesh::get_EBO(){
    return this->EBO;
}

void SIGNATURE_mesh::set_EBO(GLuint value){
    this->EBO = value;
}

void SIGNATURE_mesh::process_EBO(){
    DtoSubMesh& m = this->get_mesh();
    
    GLuint v;
    glGenBuffers(1, &v);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint8_t), m.indices, GL_STATIC_DRAW);
    
    this->set_EBO(v);
}

void SIGNATURE_mesh::init_shader_buffer(){
    DtoSubMesh& m = this->get_mesh();

    m.vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m.vertexShader, 1, &constant_shader::vertexShaderSource, NULL);
    glCompileShader(m.vertexShader);

    m.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m.fragmentShader, 1, &constant_shader::fragmentShaderSource, NULL);
    glCompileShader(m.fragmentShader);

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
    for(uint8_t i = 0;i < m.i_size;i++){
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

void SIGNATURE_mesh::calculate_count_of_attribute(){
    DtoSubMesh& m = this->get_mesh();

    m.v_size = shape::get_vertice_value_from_shape(m.shape) * 2;
    m.i_size = (m.v_size / 2) + ((m.v_size / 2) / 2);
}

void SIGNATURE_mesh::gpu_base_smart(){
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0); // UNBINDING VAO!
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void SIGNATURE_mesh::color_draw(){
    DtoSubMesh& m = this->get_mesh();
    std::vector<float> color = m.color;
    
    int c_loc = glGetUniformLocation(m.shaderProgram, "objectColor");
    glUniform4f(c_loc, color[0], color[1], color[2], color[3]);
}

void SIGNATURE_mesh::change_axist(DtoEnumAxist axist, float value){
    DtoSubMesh& m = this->get_mesh();

    uint8_t div_by = 1;
    if(axist == X){
        div_by = 0;
    }

    for(uint8_t i = 0;i < m.v_size;i++){
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
    DtoSubMesh& m = this->get_mesh();
    
    glUseProgram(m.shaderProgram);
    this->color_draw();
    
    glBindVertexArray(this->get_VAO());

    glDrawElements(GL_TRIANGLES, m.i_size, GL_UNSIGNED_BYTE, 0);
    
    glBindVertexArray(0);
}