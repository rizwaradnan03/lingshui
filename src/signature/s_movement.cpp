#include <signature/s_movement.h>

SIGNATURE_movement::SIGNATURE_movement(DtoMovement init_movement){
    this->set_mesh(init_movement.mesh);
}

SIGNATURE_mesh* SIGNATURE_movement::get_mesh(){
    return this->p_mesh;
}

void SIGNATURE_movement::set_mesh(SIGNATURE_mesh* value){
    this->p_mesh = value;
}

void SIGNATURE_movement::execute(){
    // this->gravity();
    
    std::string *input = input::mouse_pressed();
    if(input == nullptr){
        return;
    }

    SIGNATURE_mesh *mesh = this->get_mesh();

    float mv = 0.02f;
    if(*input == "RIGHT" || *input == "LEFT"){
        mesh->get_mesh().x = mesh->get_mesh().x + (*input == "RIGHT" ? mv : mv * -1);
    }
    
    GLuint model_loc = glGetUniformLocation(mesh->get_mesh().shaderProgram, "uPos");
    glUniform2f(model_loc, mesh->get_mesh().x, mesh->get_mesh().y);

    delete input;
}

void SIGNATURE_movement::gravity(){
    SIGNATURE_mesh *mesh = this->get_mesh();

    float mv = 0.01f;
    mesh->get_mesh().y -= mv;
    
    GLuint upos_loc = glGetUniformLocation(mesh->get_mesh().shaderProgram, "uPos");
    glUniform2f(upos_loc, mesh->get_mesh().x, mesh->get_mesh().y);
}