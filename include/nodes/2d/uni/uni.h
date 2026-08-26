#ifndef UNI_H
#define UNI_H

#include <dto/dto_n_uni.h>
#include <signature/s_mesh.h>

class Uni {
    public:
        Uni(DtoUni init);
        ~Uni();

        virtual SIGNATURE_mesh *get_mesh();
        virtual void set_mesh(SIGNATURE_mesh *value);

        virtual std::vector<SIGNATURE_mesh*> get_nodes();
        virtual void set_nodes(std::vector<SIGNATURE_mesh*> value);
        virtual void set_push_nodes(SIGNATURE_mesh *value);
        
        virtual uint8_t get_amount();
        virtual void set_amount(uint8_t value);
        
        virtual void execute();
        virtual void display();

    private:
        SIGNATURE_mesh *mesh;
        std::vector<SIGNATURE_mesh*> nodes; // member
        
        uint8_t amount;
};

#endif