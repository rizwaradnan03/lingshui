#ifndef RENDER_TYPE_H
#define RENDER_TYPE_H

#include <config/c_pch.h>
#include <nodes/2d/uni/uni.h>

class RenderType {
    public:
        RenderType();
        ~RenderType();
        
        virtual std::vector<Uni*> get_nodes();
        virtual void set_nodes(std::vector<Uni*> value);
        virtual void set_push_nodes(Uni* value);

        virtual void execute();
        
    private:
        std::vector<Uni*> nodes;  
};

extern RenderType *G_N_render_type; 

#endif