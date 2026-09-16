#include <nodes/2d/body/body.h>

Body::Body(DtoNodeBody init){
    DtoNodeBody dp_init = init;
    
    SIGNATURE_mesh *init_mesh = new SIGNATURE_mesh(dp_init.mesh);
    SIGNATURE_life *init_life = new SIGNATURE_life(dp_init.life);

    DtoInitSignaturePhysicalPhysic str_physic;
    str_physic.mesh = init_mesh;
    SIGNATURE_PHYSICAL_physic *init_physic = new SIGNATURE_PHYSICAL_physic(str_physic);
    
    DtoInitSignaturePhysicalMovement str_movement;
    str_movement.physic = init_physic;
    SIGNATURE_PHYSICAL_movement *init_movement = new SIGNATURE_PHYSICAL_movement(str_movement);

    this->set_mesh(init_mesh);
    this->set_life(init_life);
    this->set_physic(init_physic);
    this->set_movement(init_movement);
}

SIGNATURE_mesh *Body::get_mesh(){
    return this->mesh;
}

void Body::set_mesh(SIGNATURE_mesh *value){
    this->mesh = value;
}

SIGNATURE_life *Body::get_life(){
    return this->life;
}

void Body::set_life(SIGNATURE_life *value){
    this->life = value;
}

SIGNATURE_PHYSICAL_physic *Body::get_physic(){
    return this->physic;
}

void Body::set_physic(SIGNATURE_PHYSICAL_physic *value){
    this->physic = value;
}

SIGNATURE_PHYSICAL_movement *Body::get_movement(){
    return this->movement;
}

void Body::set_movement(SIGNATURE_PHYSICAL_movement *value){
    this->movement = value;
}

void Body::execute(){
    this->display();
    this->action();
}

void Body::display(){
    this->get_mesh()->execute();
}

void Body::action(){
    this->get_movement()->execute();
}