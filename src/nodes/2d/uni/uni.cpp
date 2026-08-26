#include <nodes/2d/uni/uni.h>

Uni::Uni(DtoUni init){
    SIGNATURE_mesh *init_mesh = new SIGNATURE_mesh(init.mesh);
    this->set_mesh(init_mesh);

    this->set_amount(init.amount);
}

Uni::~Uni(){
    delete this->get_mesh();

    std::vector<SIGNATURE_mesh*> n = this->get_nodes();
    for(uint16_t i = 0;i < n.size();i++){
        delete n[i];
    }
}

SIGNATURE_mesh *Uni::get_mesh(){
    return this->mesh;
}

void Uni::set_mesh(SIGNATURE_mesh *value){
    this->mesh = value;
}

std::vector<SIGNATURE_mesh*> Uni::get_nodes(){
    return this->nodes;
}

void Uni::set_nodes(std::vector<SIGNATURE_mesh*> value){
    this->nodes = value;
}

void Uni::set_push_nodes(SIGNATURE_mesh *value){
    this->nodes.push_back(value);
}

uint8_t Uni::get_amount(){
    return this->amount;
}

void Uni::set_amount(uint8_t value){
    this->amount = value;
}

void Uni::execute(){
    this->display();
}

void Uni::display(){
    this->get_mesh()->execute();
    for(uint16_t i = 0;i < this->get_nodes().size();i++){
        SIGNATURE_mesh* m = this->get_nodes()[i];
        if(m == nullptr){
            delete m;
            this->get_nodes().erase(this->get_nodes().begin() + i);
            i--;
        }else{
            m->execute();
        }
    }
}