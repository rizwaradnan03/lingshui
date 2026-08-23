#ifndef DTO_SIGNATURE_MESH_H
#define DTO_SIGNATURE_MESH_H

#include <config/c_pch.h>

struct DtoSubMesh {
    std::vector<GLfloat> raw_vertices;

    GLfloat vertices[255]; // VERTEX
    GLfloat indices[255]; // EBO NEEDED

    // SHADER BUFFER 
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
};

struct DtoInitSignatureMesh {
    DtoSubMesh mesh;
};

#endif