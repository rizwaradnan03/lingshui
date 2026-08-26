#ifndef DTO_SIGNATURE_LIFE_H
#define DTO_SIGNATURE_LIFE_H

#include <config/c_pch.h>
#include <dto/dto_g_effect.h>

struct DtoSignatureLife {
    uint8_t health_point;
    std::vector<DtoEnumGlobalEffect> effects;
};

#endif