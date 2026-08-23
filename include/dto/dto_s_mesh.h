#ifndef DTO_SIGNATURE_MESH_H
#define DTO_SIGNATURE_MESH_H

#include <config/c_pch.h>

struct DtoSubMesh {
    float x, y, w, h;
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