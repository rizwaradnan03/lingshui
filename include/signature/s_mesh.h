#ifndef SIGNATURE_MESH_H
#define SIGNATURE_MESH_H

#include <config/c_pch.h>
#include <constants/ct_shader.h>
#include <constants/ct_default.h>
#include <dto/dto_s_mesh.h>
#include <dto/dto_g_axist.h>
#include <namespace/n_shape.h>

class SIGNATURE_mesh {
    public:
        SIGNATURE_mesh(const DtoSubMesh& init);
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

        float get_x();
        void set_x(float value);
        float get_y();
        void set_y(float value);
        float get_w();
        void set_w(float value);
        float get_h();
        void set_h(float value);

        DtoGlobalPole& get_pole();
        void set_pole(DtoGlobalPole value);

        uint8_t get_v_size();
        void set_v_size(uint8_t value);
        uint8_t get_i_size();
        void set_i_size(uint8_t value);

        float get_w_pixel();
        void set_w_pixel(float value);

        float get_h_pixel();
        void set_h_pixel(float value);
        
        float get_top();
        float get_bottom();
        float get_right();
        float get_left();
        
        void execute();

    private:
        GLuint VAO = 0, VBO = 0, EBO = 0;
        DtoSubMesh mesh;
};

#endif