#include <Engine.hpp>
#include <Input.hpp>

namespace Game {
  GameProcess* GameProcess::gp = nullptr;
  
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
          default:
            break;
        };
      };

      if(Input::fire(Keyboard::P)) setPaused(true);
      if((this->frame)/60 <= elapsed.asSeconds()) {
        this->nextFrame();
      };
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

    for(unsigned int i = 0; i < this->buttons.length(); i++){
      Button* button = this->buttons.get(i);
      if(button->getText() != nullptr) {
        if(!button->isPausable() && this->isPaused) button->getText()->setVisible(button->isVisible());
        else if(button->isPausable() && !this->isPaused) button->getText()->setVisible(button->isVisible());
        else button->getText()->setVisible(false);
      };
    };

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      if(object->isPausable() && !this->isPaused && object->isVisible()){
        object->draw();
        object->collision();
        object->step();
      } else if(!object->isPausable() && this->isPaused && object->isVisible()){
        object->collision();
        object->step();
        object->draw();
      } else if(object->isPausable() && object->isVisible()){
        object->draw();
      }; 
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

  bool GameProcess::checkPaused(){
    return this->isPaused;
  };

  void GameProcess::setPaused(bool pause){
    this->isPaused = pause;
  };

  void GameProcess::resizeWindow(unsigned int newWidth, unsigned int newHeigth){
    // this->width = newWidth;
    // this->height = newHeigth;
  };
};