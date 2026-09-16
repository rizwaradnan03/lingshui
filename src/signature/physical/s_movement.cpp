#include <signature/physical/s_movement.h>

SIGNATURE_PHYSICAL_movement::SIGNATURE_PHYSICAL_movement(DtoInitSignaturePhysicalMovement init){
    this->set_physic(init.physic);
}

SIGNATURE_PHYSICAL_physic *SIGNATURE_PHYSICAL_movement::get_physic(){
    return this->physic;
}

void SIGNATURE_PHYSICAL_movement::set_physic(SIGNATURE_PHYSICAL_physic *value){
    this->physic = value;
}

void SIGNATURE_PHYSICAL_movement::execute(){
    // this->gravity();
    
    std::string *input = input::mouse_pressed();
    if(input == nullptr){
        return;
    }

    SIGNATURE_mesh *mesh = this->get_physic()->get_mesh();

    float mv = 0.02f;
    if(*input == "RIGHT" || *input == "LEFT"){
        mesh->get_mesh().x = mesh->get_mesh().x + (*input == "RIGHT" ? mv : mv * -1);
    }
    
    GLuint model_loc = glGetUniformLocation(mesh->get_mesh().shaderProgram, "uPos");
    glUniform2f(model_loc, mesh->get_mesh().x, mesh->get_mesh().y);

    delete input;
}

void SIGNATURE_PHYSICAL_movement::gravity(){
    SIGNATURE_mesh *mesh = this->get_physic()->get_mesh();

    float mv = 0.01f;
    mesh->get_mesh().y -= mv;
    
    GLuint upos_loc = glGetUniformLocation(mesh->get_mesh().shaderProgram, "uPos");
    glUniform2f(upos_loc, mesh->get_mesh().x, mesh->get_mesh().y);
}