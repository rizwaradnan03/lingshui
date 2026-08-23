#include <signature/s_mesh.h>

SIGNATURE_mesh::SIGNATURE_mesh(DtoInitSignatureMesh init){
    DtoSubMesh mesh = init.mesh;

    uint8_t sz = mesh.raw_vertices.size();
    for(uint8_t i = 0;i < sz;i++){
        mesh.vertices[i] = mesh.raw_vertices[i];
    }
    
    this->set_mesh(mesh);
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
    
    GLuint v;
    glGenBuffers(1, &v);
    glBindBuffer(GL_ARRAY_BUFFER, v);

    glBufferData(GL_ARRAY_BUFFER, m.raw_vertices.size() * sizeof(float), m.vertices, GL_STATIC_DRAW); // SIGNING VERTICES INTO VBO
    
    this->set_VBO(v);
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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m.indices), m.indices, GL_STATIC_DRAW);
    
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
    
    uint8_t sz = m.raw_vertices.size();
    
    uint8_t ctvb = (sz / 2) + ((sz / 2) / 2);
    for(uint8_t i = 0;i < ctvb;i++){
        uint8_t decr_by = 0;
        if(i % 3 == 0 || i == ctvb - 1){
            if(i == ctvb - 1){
                decr_by = i;
            }else{
                decr_by = i / 3;
            }
        }

        m.indices[i] = i - decr_by;
    }
}

void SIGNATURE_mesh::gpu_base_smart(){
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SIGNATURE_mesh::display(){
    DtoSubMesh& m = this->get_mesh();
    
    glUseProgram(m.shaderProgram);
    glBindVertexArray(this->get_VAO());

    uint8_t sz = m.raw_vertices.size();
    uint8_t ctvb = (sz / 2) + ((sz / 2) / 2);
    glDrawElements(GL_TRIANGLES, ctvb, GL_UNSIGNED_BYTE, 0);
}

void SIGNATURE_mesh::execute(){
    this->display();
}