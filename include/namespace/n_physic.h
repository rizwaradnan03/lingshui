#ifndef NAMESPACE_PHYSIC_H
#define NAMESPACE_PHYSIC_H

#include <config/c_pch.h>
#include <signature/s_mesh.h>

namespace physic {
    std::string *check_collision(SIGNATURE_mesh *me, SIGNATURE_mesh *enemy);
};

#endif
