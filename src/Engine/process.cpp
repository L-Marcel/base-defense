#include <Engine.hpp>
#include <Input.hpp>

namespace Game {
  GameProcess* GameProcess::gp = nullptr;
  bool GameProcess::paused = false;
  
  GameProcess::~GameProcess() {
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      this->objects.remove(object);
      object->free();
    };

    // for(unsigned int i = 0; i < this->buttons.length(); i++) {
    //   Button* button = this->buttons.get(i);
    //   button->free();
    // };

    this->gp = nullptr;
  };

  GameProcess::GameProcess() {
    if(this->gp != nullptr) {
      delete this->gp;
    };
    
    this->gp = this;
    this->window.setFramerateLimit(60);
  };

  void GameProcess::add(Object* object) {
    GameProcess::gp->objects.add(object);
  };

  void GameProcess::destroy(Object* object) {
    GameProcess::gp->queueFree.add(object);
  };

  unsigned short int GameProcess::length() {
    return GameProcess::gp->objects.length();
  };

  const Window& GameProcess::getWindow() {
    return GameProcess::gp->window;
  };

  Object* GameProcess::get(unsigned short int index) {
    return GameProcess::gp->objects.get(index);
  };

  void GameProcess::draw(const Drawable& drawable) {
    GameProcess::gp->window.draw(drawable);
  };

  void GameProcess::execute() {
    while(this->isRunning()) {
      Time elapsed = this->clock.getElapsedTime();

      Event event;
      while(window.pollEvent(event)) {
        switch(event.type) {
          case Event::Closed:
            this->window.close();
            break;
          case Event::Resized:
            break;
          case Event::KeyPressed:
            Input::press(event.key.code);
            break;
          case Event::KeyReleased:
            Input::release(event.key.code);
            break;
          case Event::MouseButtonPressed:
            Mouse::press(event.mouseButton.button);
            break;
          case Event::MouseButtonReleased:
            Mouse::release(event.mouseButton.button);
            break;
          default:
            break;
        };
      };

      if((this->frame)/60 <= elapsed.asSeconds()) this->nextFrame();
      if(Input::isPressed(Keyboard::Escape)) this->paused = !this->paused;

      Input::update();
      Mouse::update();
    };

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      this->objects.remove(object);
      object->free();
    };

    this->objects.clear();
  };

  void GameProcess::animate(Object2D* object) {
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

  void GameProcess::sort() {
    this->objects.sort([](Object* a, Object* b) {
      return a->depth <= b->depth;
    });
  };

  unsigned short int GameProcess::getFrame() {
    return GameProcess::gp->frame;
  };

  void GameProcess::nextFrame() {
    if(this->frame < 60) this->frame++;
    else {
      this->frame = 0;
      this->clock.restart();
    };

    this->window.clear();

    if(!this->objects.isSorted()) {
      this->sort();
    };

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);

      if(!object->isPausable()) object->step();
      else if(!this->paused) {
        object->collision();
        object->step();
      };

      if(object->visible) object->draw();
    };

    this->window.display();

    for(unsigned int i = 0; i < this->queueFree.length(); i++) {
      Object* object = this->queueFree.get(i);
      this->objects.remove(object);
      this->queueFree.remove(i);
      object->free();
    };
  };

  bool GameProcess::isRunning() {
    return this->window.isOpen();
  };

  void GameProcess::resizeWindow(unsigned int newWidth, unsigned int newHeigth){
    // this->width = newWidth;
    // this->height = newHeigth;
  };
};