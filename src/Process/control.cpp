#include <Engine.hpp>

namespace Game {
  void GameProcess::add(Object* object) {
    GameProcess::gp->objects.add(object);
  };

  void GameProcess::destroy(Object* object) {
    GameProcess::gp->queueFree.add(object);
  };

  unsigned short int GameProcess::length() {
    return GameProcess::gp->objects.length();
  };

  Object* GameProcess::get(unsigned short int index) {
    return GameProcess::gp->objects.get(index);
  };
};