#include <Objects/example.hpp>

namespace Game{
    string Example::type(){
        return "Example";
    };

    void Example::draw(){
        if(this->hasCircle){
            this->gp->window.draw(this->circle);
        } else if(this->hasRectangle){
            this->gp->window.draw(this->rectangle);
        }
    };

    Example::~Example() {};

    Example* Example::create(GameProcess* gp, string spriteSheet, Box box) {
        Example* example = new Example(spriteSheet, box);
        example->gp = gp;
        gp->objects.add(example);
        return example;
    };
};