#ifndef SIGNATURE_LIFE_H
#define SIGNATURE_LIFE_H

#include <config/c_pch.h>
#include <dto/dto_s_life.h>
#include <dto/dto_g_effect.h>

class SIGNATURE_life {
    public:
        SIGNATURE_life(DtoSignatureLife init);
        ~SIGNATURE_life();

        uint8_t get_health_point();
        void set_health_point(uint8_t value);

        std::vector<DtoEnumGlobalEffect> get_effects();
        void set_effects(std::vector<DtoEnumGlobalEffect> value);
        void set_push_effects(DtoEnumGlobalEffect value);
        
    private:
        uint8_t health_point;
        std::vector<DtoEnumGlobalEffect> effects;
};

#endif