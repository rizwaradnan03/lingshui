#include <namespace/n_physic.h>

namespace physic {
    std::string *check_collision(SIGNATURE_mesh *me, SIGNATURE_mesh *enemy){
        std::string *dir = nullptr;

        float me_top = me->get_top();
        float me_bottom = me->get_bottom();
        float me_right = me->get_right();
        float me_left = me->get_left();
        
        float enemy_top = enemy->get_top();
        float enemy_bottom = enemy->get_bottom();
        float enemy_right = enemy->get_right();
        float enemy_left = enemy->get_left();
        
        // RIGHT AND LEFT FIRST
        if(me_right >=enemy_left && me_top >= enemy_bottom){ // THE NEXT IS THE TOP AND BOTTOM MUST BE AROUND !
            dir = new std::string("RIGHT");
        }else if(me_left <= enemy_right && me_top >= enemy_bottom){
            dir = new std::string("LEFT");
        }else if(me_top >= enemy_bottom && me_right >= enemy_left){
            dir = new std::string("TOP");
        }else if(me_bottom <= enemy_top && me_right >= enemy_left){
            dir = new std::string("BOTTOM");
        }
        
        return dir;
    }
};