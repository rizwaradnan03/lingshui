#ifndef RENDER_TYPE_WORLD_H
#define RENDER_TYPE_WORLD_H

// #include <config
#include <config/c_pch.h>
#include <nodes/2d/uni/uni.h>

class RT_world {
    public:
        RT_world();
        ~RT_world();
        
        std::vector<Uni*> get_nodes();
        void set_nodes(std::vector<Uni*> value);
        void set_push_nodes(Uni* value);

        void execute();
        
    private:
        // std::vector
        std::vector<Uni*> nodes;  
};

extern RT_world *G_N_render_type; 

#endif