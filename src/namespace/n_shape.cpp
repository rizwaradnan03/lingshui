#include <namespace/n_shape.h>

namespace shape {
    uint8_t get_vertice_value_from_shape(DtoEnumGlobalShape shape){
        if(shape == TRIANGLE){
            return 3;
        }else if(shape == RECTANGLE){
            return 4;
        }

        return 0;
    }
};