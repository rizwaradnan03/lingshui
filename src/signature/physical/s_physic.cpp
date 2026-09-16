#include <signature/physical/s_physic.h>

SIGNATURE_PHYSICAL_physic::SIGNATURE_PHYSICAL_physic(DtoInitSignaturePhysicalPhysic init){
    this->set_mesh(init.mesh);
}

SIGNATURE_mesh *SIGNATURE_PHYSICAL_physic::get_mesh(){
    return this->mesh;
}

void SIGNATURE_PHYSICAL_physic::set_mesh(SIGNATURE_mesh *value){
    this->mesh = value;
}

DtoValueOfPhysic &SIGNATURE_PHYSICAL_physic::get_value(){
    return this->value;
}

void SIGNATURE_PHYSICAL_physic::set_value(DtoValueOfPhysic value){
    this->value = value;
}

std::vector<float> SIGNATURE_PHYSICAL_physic::get_available_direction(){
    return this->value.available_direction;
}

void SIGNATURE_PHYSICAL_physic::set_available_direction(std::vector<float> value){
    this->value.available_direction = value;
}