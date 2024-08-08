#include <Engine.hpp>
#include <Input.hpp>

namespace Game {
  GameProcess* GameProcess::gp = nullptr;
  unsigned int GameProcess::money = 0;
  int GameProcess::current = 0;
  int GameProcess::max = 10;

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

      bool pauseRequested = Input::isPressed(Keyboard::Escape);
      if(
        pauseRequested && this->paused && 
        this->menu != nullptr && this->menu->type() != "ShopMenu"
      ) this->resume();
      else if(pauseRequested && this->menu == nullptr) this->pause();
      else if(Input::isPressed(Keyboard::S)) this->pause(true);

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

  void GameProcess::sort() {
    this->objects.sort([](Object* a, Object* b) {
      return a->depth <= b->depth;
    });
  };

  bool GameProcess::isRunning() {
    return this->window.isOpen();
  };

  void GameProcess::nextFrame() {
    if(this->frame < 60) this->frame++;
    else {
      this->frame = 0;
      this->clock.restart();
    };

    this->window.clear();

    if(this->frame_instances_amount != this->objects.length() || !this->objects.isSorted()) {
      this->sort();
      this->frame_instances_amount = this->objects.length();
    };

    for(unsigned int i = 0; i < this->frame_instances_amount; i++) {
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

  GameProcess::~GameProcess() {
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      this->objects.remove(object);
      object->free();
    };

    this->gp = nullptr;
  };

  GameProcess::GameProcess() {
    if(this->gp != nullptr) {
      delete this->gp;
    };
    srand (time(NULL));
    this->gp = this;
    this->window.setFramerateLimit(60);
  };
};