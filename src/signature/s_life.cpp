#include <signature/s_life.h>

SIGNATURE_life::SIGNATURE_life(DtoSignatureLife init){
    
}

uint8_t SIGNATURE_life::get_health_point(){
    return this->health_point;
}

void SIGNATURE_life::set_health_point(uint8_t value){
    this->health_point = value;
}

std::vector<DtoEnumGlobalEffect> SIGNATURE_life::get_effects(){
    return this->effects;
}

void SIGNATURE_life::set_effects(std::vector<DtoEnumGlobalEffect> value){
    this->effects = value;
}

void SIGNATURE_life::set_push_effects(DtoEnumGlobalEffect value){
    this->effects.push_back(value);
}