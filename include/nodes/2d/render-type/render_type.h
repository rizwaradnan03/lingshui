#ifndef RENDER_TYPE_H
#define RENDER_TYPE_H

#include <config/c_pch.h>
#include <nodes/2d/uni/uni.h>

// VECTOR OF UNI WITH ID

class RenderType {
    public:
        RenderType();
        ~RenderType();
        
        std::vector<Uni*> get_nodes();
        void set_nodes(std::vector<Uni*> value);
        void set_push_nodes(Uni* value);

        void execute();
        
    private:
        std::vector<Uni*> nodes;  
};

#endif