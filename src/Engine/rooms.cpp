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

  void Room::step(GameProcess* gp, RenderWindow* window, unsigned short int frame) {
    this->objects.sort([](Object* one, Object* two) {
      return one->depth < two->depth;
    });

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      object->draw(window, frame);
      object->onStep(object, this, gp);
    };
  };

  unsigned int Room::addObject(Object* object) {
    object->defineId(&this->objects);
    this->objects.push(object);
    return object->getId();
  };
};