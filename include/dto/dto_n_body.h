#ifndef DTO_NODE_BODY_H
#define DTO_NODE_BODY_H

#include <dto/dto_s_mesh.h>
#include <dto/dto_s_life.h>
#include <dto/dto_s_movement.h>

struct DtoNodeBody {
    DtoSubMesh mesh;
    DtoSignatureLife life;
    DtoMovement movement;
};

#endif