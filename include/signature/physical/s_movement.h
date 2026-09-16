#ifndef SIGNATURE_PHYSICAL_MOVEMENT_H
#define SIGNATURE_PHYSICAL_MOVEMENT_H

#include <namespace/n_input.h>
#include <signature/physical/s_physic.h>

struct DtoInitSignaturePhysicalMovement {
  SIGNATURE_PHYSICAL_physic *physic;  
};

class SIGNATURE_PHYSICAL_movement {
    public:
        SIGNATURE_PHYSICAL_movement(DtoInitSignaturePhysicalMovement init);

        SIGNATURE_PHYSICAL_physic *get_physic();
        void set_physic(SIGNATURE_PHYSICAL_physic *value);
        
        void execute();
        void gravity();
        
    private:
        SIGNATURE_PHYSICAL_physic *physic;
};

#endif