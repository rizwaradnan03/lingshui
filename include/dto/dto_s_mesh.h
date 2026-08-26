#ifndef DTO_SIGNATURE_MESH_H
#define DTO_SIGNATURE_MESH_H

#include <config/c_pch.h>
#include <dto/dto_g_pole.h>

struct DtoSubMesh {
    float x = 0, y = 0, w, h;
    DtoGlobalPole pole;
    std::vector<float> color;

    uint8_t v_size;
    uint8_t i_size;
    std::vector<float> raw_vertices;
    float vertices[255];
    uint8_t indices[255];

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
};

#endif