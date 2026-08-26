#ifndef DTO_NODE_UNI_H
#define DTO_NODE_UNI_H

#include <config/c_pch.h>
#include <dto/dto_s_mesh.h>

struct DtoUni {
    DtoSubMesh mesh;
    uint8_t amount = 1;
};

#endif