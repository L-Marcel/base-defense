#include <Objects/example.hpp>

namespace Game{
    void Example::step(GameProcess* gp){
        //APENAS PARA DEBUG
        /*
        if(this->hasCCol == true){
            gp->window.draw(this->circ_collision);
        } else if(this->hasRCol == true){
            gp->window.draw(this->rect_collision);
        }
        */
    };

    string Example::type(){
        return "Example";
    }
};