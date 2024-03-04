#include "../../include/Engine.hpp"

namespace lm {
  Room::Room() {
    this->title = "";
    this->width = 800;
    this->height = 600;
  };

  Room::Room(string title, unsigned int width = 800, unsigned int height = 600) {
    this->title = title;
    this->width = width;
    this->height = height;
  };

  void Room::step(GameProcess* gp, Window* window, unsigned short int frame) {
    this->objects.sort([](Object* one, Object* two) {
      return one->depth < two->depth;
    });

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);

      object->step(this, gp);

      sf::IntRect old = object->sprite->getTextureRect();
      Vector<unsigned int> size = object->sprite->getTexture()->getSize();
      object->image += object->fps/60.f;

      int image = int(floor(object->image)) * old.width;

      if(!object->loop) {
        image = min(image, int(size.x) - old.width);
      };
      
      object->animationFinished = image == int(size.x) - old.width;
      object->sprite->setTextureRect(Box(image % size.x, old.top, old.width, old.height));
      object->sprite->setPosition(object->x, object->y);
      object->sprite->setRotation(object->rotation);
      
      window->draw(*object->sprite);
    };
  };

  unsigned int Room::addObject(Object* object) {
    object->defineId(&this->objects);
    this->objects.push(object);
    return object->getId();
  };
};