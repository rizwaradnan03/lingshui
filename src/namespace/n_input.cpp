#include <namespace/n_input.h>

namespace input {
  std::string* mouse_pressed(){
      std::string* ret = nullptr;

      if(glfwGetKey(G_C_gl->get_window(), GLFW_KEY_W)){
          ret = new std::string("TOP");
      }else if(glfwGetKey(G_C_gl->get_window(), GLFW_KEY_S)){
          ret = new std::string("BOTTOM");
      }else if(glfwGetKey(G_C_gl->get_window(), GLFW_KEY_A)){
          ret = new std::string("LEFT");
      }else if(glfwGetKey(G_C_gl->get_window(), GLFW_KEY_D)){
          ret = new std::string("RIGHT");
      }
      
      return ret;
  }  
};