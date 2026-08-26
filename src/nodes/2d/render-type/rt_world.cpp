#include <nodes/2d/render-type/rt_world.h>

RT_world::RT_world(): RenderType(){
    DtoSubMesh p_mesh;
    p_mesh.w = 30;
    p_mesh.h = 30;
    p_mesh.x = 0;
    p_mesh.y = 0;

    DtoSignatureLife p_life;
    p_life.health_point = 100;
    p_life.effects = std::vector<DtoEnumGlobalEffect>{
        BURN
    };
    
    DtoNodeBody p_body;
    p_body.mesh = p_mesh;
    p_body.life = p_life;
    
    Body *player = new Body(p_body);
}

RT_world::~RT_world(){
    std::vector<Uni*> unis = this->get_nodes();
    for(uint16_t i = 0;i < unis.size();i++){
        delete unis[i];
    }
}

Body *RT_world::get_player(){
    return this->player;
}

void RT_world::set_player(Body *value){
    this->player = value;
}

std::vector<Body*> RT_world::get_bodies(){
    return this->bodies;
}

void RT_world::set_bodies(std::vector<Body*> value){
    this->bodies = value;
}

void RT_world::set_push_bodies(Body* value){
    this->bodies.push_back(value);
}

std::vector<Uni*> RT_world::get_nodes(){
    return this->nodes;
}

void RT_world::set_nodes(std::vector<Uni*> value){
    this->nodes = value;
}

void RT_world::set_push_nodes(Uni* value){
    this->nodes.push_back(value);
}

void RT_world::execute(){
    // for(uint16_t i = 0;i < this->get_bodies().size();i++){
    //     Body *b = this->get_bodies()[i];
    //     if(b == nullptr){
    //         delete b;
    //         this->get_bodies().erase(this->get_bodies().begin() + i);
    //         i--;
    //     }
    // }

    for(uint16_t i = 0;i < this->get_nodes().size();i++){
        Uni *n = this->get_nodes()[i];
        if(n == nullptr){
            this->get_nodes().erase(this->get_nodes().begin() + i);
            i--;
        }else{
            n->execute();
        }
    }
}