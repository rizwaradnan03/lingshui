#include <nodes/2d/uni/uni_wear.h>

UNI_wear::UNI_wear(DtoUni init): Uni(init){
    SIGNATURE_mesh *init_mesh = new SIGNATURE_mesh(init.mesh);
    this->set_mesh(init_mesh);

    this->set_amount(init.amount);
}

UNI_wear::~UNI_wear(){
    delete this->get_mesh();
}

SIGNATURE_mesh *UNI_wear::get_mesh(){
    return this->mesh;
}

void UNI_wear::set_mesh(SIGNATURE_mesh *value){
    this->mesh = value;
}

std::vector<SIGNATURE_mesh*> UNI_wear::get_nodes(){
    return this->nodes;
}

void UNI_wear::set_nodes(std::vector<SIGNATURE_mesh*> value){
    this->nodes = value;
}

void UNI_wear::set_push_nodes(SIGNATURE_mesh *value){
    this->nodes.push_back(value);
}

uint8_t UNI_wear::get_amount(){
    return this->amount;
}

void UNI_wear::set_amount(uint8_t value){
    this->amount = value;
}

void UNI_wear::execute(){
    this->display();
}

void UNI_wear::display(){
    this->get_mesh()->execute();
}

void UNI_wear::action(){}