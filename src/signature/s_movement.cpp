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

void execute(){
    
}