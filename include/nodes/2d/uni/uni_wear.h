#ifndef UNI_WEAR_H
#define UNI_WEAR_H

#include <config/c_pch.h>
#include <dto/dto_n_uni.h>
#include <signature/s_mesh.h>
#include <nodes/2d/uni/uni.h>

class UNI_wear: public Uni {
    public:
        UNI_wear(DtoUni init);
        ~UNI_wear();

        SIGNATURE_mesh *get_mesh() override;
        void set_mesh(SIGNATURE_mesh *value) override;

        std::vector<SIGNATURE_mesh*> get_nodes() override;
        void set_nodes(std::vector<SIGNATURE_mesh*> value) override;
        void set_push_nodes(SIGNATURE_mesh *value) override;
        
        uint8_t get_amount() override;
        void set_amount(uint8_t value) override;
        
        void execute() override;
        void display() override;
        void action();

    private:
        SIGNATURE_mesh *mesh;
        std::vector<SIGNATURE_mesh*> nodes;

        uint8_t amount;
};

#endif