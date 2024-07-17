#include <Objects/example.hpp>

namespace Game{
    void Example::step(GameProcess* gp){
        if(this->hasCCol == true){
            this->circ_collision.setPosition(this->x, this->y);
            this->circ_collision.setFillColor(sf::Color::Red);
            gp->window.draw(circ_collision);
        }
    };

    string Example::type(){
        return "Example";
    }
};