#ifndef DTO_SIGNATURE_MESH_H
#define DTO_SIGNATURE_MESH_H

#include <config/c_pch.h>
#include <dto/dto_g_pole.h>
#include <dto/dto_g_shape.h>

struct DtoSubMesh {
    // REQUIRED
    float x = 0, y = 0, w, h;
    DtoEnumGlobalShape shape;
    bool is_render = true;
    
    DtoGlobalPole pole;
    std::vector<float> color;

    uint8_t v_size;
    uint8_t i_size;
    float vertices[255];
    uint8_t indices[255];

    // PIXEL OF SCREEN VALUE !
    float w_pixel;
    float h_pixel;

    bool is_collide = true;
    bool available_direction[4];
    
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
};

#endif