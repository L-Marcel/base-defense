#include <Objects/legs.hpp>

namespace Game{
  string Legs::type(){
    return "Leg";
  };

  Legs::~Legs(){};

  Legs* Legs::create(string spriteSheet, Box box){
    Legs* legs = new Legs(spriteSheet, box);
    return legs;
  };
}