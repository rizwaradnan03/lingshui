#include <nodes/2d/render-type/render_type.h>

RenderType *G_N_render_type = nullptr;

RenderType::RenderType(){}

RenderType::~RenderType(){
    std::vector<Uni*> unis = this->get_nodes();
    for(uint16_t i = 0;i < unis.size();i++){
        delete unis[i];
    }
}

std::vector<Uni*> RenderType::get_nodes(){
    return this->nodes;
}

void RenderType::set_nodes(std::vector<Uni*> value){
    this->nodes = value;
}

void RenderType::set_push_nodes(Uni* value){
    this->nodes.push_back(value);
}

void RenderType::execute(){}