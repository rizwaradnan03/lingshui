#ifndef BODY_H
#define BODY_H

#include <config/c_pch.h>
#include <dto/dto_n_body.h>
#include <signature/s_mesh.h>
#include <signature/s_life.h>
#include <signature/s_movement.h>

class Body {
    public:
        Body(DtoNodeBody init);
        ~Body();
        
        SIGNATURE_mesh *get_mesh();
        void set_mesh(SIGNATURE_mesh *value);

        SIGNATURE_life *get_life();
        void set_life(SIGNATURE_life *value);
        
        SIGNATURE_movement *get_movement();
        void set_movement(SIGNATURE_movement *value);

        void execute();
        void display();
        void action();

    private:
        SIGNATURE_mesh *mesh;
        SIGNATURE_life *life;
        SIGNATURE_movement *movement;
};

#endif