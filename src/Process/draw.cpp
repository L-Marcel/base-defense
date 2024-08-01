#include <Engine.hpp>

namespace Game {
  void GameProcess::draw(const Drawable& drawable) {
    GameProcess::gp->window.draw(drawable);
  };

  void GameProcess::animate(Object2D* object) {
    if(GameProcess::gp->paused && object->isPausable()) {
      return;
    };

    sf::IntRect old = object->sprite->getTextureRect();
    object->image += object->fps/60.f;

    int image = int(floor(object->image)) * old.width;

    if(object->loop) {
      image = image % (object->frames * old.width);
    } else {
      image = min(image, (object->frames - 1) * old.width);
    }
    
    object->animationFinished = image == (object->frames - 1) * old.width;
    object->sprite->setTextureRect(Box(image, old.top, old.width, old.height));
    object->sprite->setPosition(object->position.x, object->position.y);
    object->sprite->setRotation(object->rotation);
  };

  unsigned short int GameProcess::getFrame() {
    return GameProcess::gp->frame;
  };
};