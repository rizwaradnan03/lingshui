#ifndef SIGNATURE_MOVEMENT_H
#define SIGNATURE_MOVEMENT_H

#include <dto/dto_s_movement.h>
#include <signature/s_mesh.h>

class SIGNATURE_movement {
    public:
        SIGNATURE_movement(DtoMovement init_movement);

        SIGNATURE_mesh* get_mesh();
        void set_mesh(SIGNATURE_mesh* value);
        
        void execute();

    private:
        SIGNATURE_mesh* p_mesh;
};

#endif