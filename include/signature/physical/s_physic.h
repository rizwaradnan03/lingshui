#ifndef SIGNATURE_PHYSICAL_PHYSIC_H
#define SIGNATURE_PHYSICAL_PHYSIC_H

#include <namespace/n_input.h>
#include <signature/s_mesh.h>

struct DtoInitSignaturePhysicalPhysic {
  SIGNATURE_mesh *mesh;  
};

struct DtoValueOfPhysic {
    std::vector<float> available_direction;
};


class SIGNATURE_PHYSICAL_physic { // BASIC PHYSIC
    public:
        SIGNATURE_PHYSICAL_physic(DtoInitSignaturePhysicalPhysic init);

        SIGNATURE_mesh *get_mesh();
        void set_mesh(SIGNATURE_mesh *value);

        DtoValueOfPhysic &get_value();
        void set_value(DtoValueOfPhysic value);
        
        std::vector<float> get_available_direction();
        void set_available_direction(std::vector<float> value);
        
    private:
        SIGNATURE_mesh *mesh;
        DtoValueOfPhysic value;
};

#endif