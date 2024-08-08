#include <Objects/image.hpp>

namespace Game{
  string Image::type(){
    return "Leg";
  };

  Image::~Image(){};

  Image* Image::create(string spriteSheet, Box box){
    Image* image = new Image(spriteSheet, box);
    return image;
  };
}