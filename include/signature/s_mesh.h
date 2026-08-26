#ifndef SIGNATURE_MESH_H
#define SIGNATURE_MESH_H

#include <config/c_pch.h>
#include <constants/ct_shader.h>
#include <dto/dto_s_mesh.h>
#include <dto/dto_g_axist.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(DtoSubMesh init);
        ~SIGNATURE_mesh();
        
        GLuint get_VAO();
        void set_VAO(GLuint value);
        void process_VAO();
        
        GLuint get_VBO();
        void set_VBO(GLuint value);
        void process_VBO();
        
        GLuint get_EBO();
        void set_EBO(GLuint value);
        void process_EBO();
        
        DtoSubMesh& get_mesh();
        void set_mesh(DtoSubMesh value);

        void init_shader_buffer();
        
        void calculate_ebo();
        void calculate_count_of_attribute();
        void gpu_base_smart();
        
        void display();
        void color_draw();

        void change_axist(DtoEnumAxist axist, float value);
        
        void execute();

    private:
        GLuint VAO, VBO, EBO;
        
        DtoSubMesh mesh;
};

#endif