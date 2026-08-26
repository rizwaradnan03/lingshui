#ifndef RENDER_TYPE_WORLD_H
#define RENDER_TYPE_WORLD_H

#include <config/c_pch.h>
#include <nodes/2d/render-type/render_type.h>
#include <nodes/2d/uni/uni.h>
#include <nodes/2d/body/body.h>

class RT_world: public RenderType {
    public:
        RT_world();
        ~RT_world();

        Body *get_player();
        void set_player(Body *value);
        
        std::vector<Body*> get_bodies();
        void set_bodies(std::vector<Body*> value);
        void set_push_bodies(Body* value);
        
        std::vector<Uni*> get_nodes() override;
        void set_nodes(std::vector<Uni*> value) override;
        void set_push_nodes(Uni* value) override;

        void execute() override;
        
    private:        
        Body* player;
        std::vector<Body*> bodies;
        std::vector<Uni*> nodes;  
};

#endif