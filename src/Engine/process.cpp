#include <Engine.hpp>

namespace Game {
  GameProcess::GameProcess() {
    this->redraw = true;
    this->window.setFramerateLimit(60);
    this->events = [](Event::EventType ev) {};
  };

  GameProcess::GameProcess(
    unsigned short int width = 800,
    unsigned short int height = 600,
    string title = "Base Defense"
  ) {
    this->title = title;
    this->width = width;
    this->height = height;

    this->window.setSize(Vector<unsigned int>(width, height));
    this->window.setTitle(title);
    this->redraw = true;
    this->window.setFramerateLimit(60);
    this->events = [](Event::EventType ev) {};
  };

  void GameProcess::on(void (*func)(Event::EventType)) {
    this->events = func;
  };

  void GameProcess::execute() {
    while(this->isRunning()) {
      Time elapsed = this->clock.getElapsedTime();

      if((this->frame)/60 <= elapsed.asSeconds()) {
        this->nextFrame();
        this->redraw = true;
      };

      Event event;
      while (window.pollEvent(event)) {
        this->events(event.type);
        switch(event.type) {
          case Event::Closed:
            this->window.close();
            break;
          case Event::Resized:
            this->width = event.size.width;
            this->height = event.size.height;
            break;
          default:
            break;
        };
      };
      
      if(this->redraw) {
        this->window.clear();

        for(unsigned int i = 0; i < this->objects.length(); i++) {
          Object* object = this->objects.get(i);

          object->step(this);

          if(object->hasCCol == true){
            object->circ_collision.setPosition(object->x, object->y);
          } else if(object->hasRCol == true){
            object->rect_collision.setPosition(object->x, object->y);
          }

          this->animateObject(object);
          
          this->window.draw(*object->sprite);
        };

        for(unsigned int i = 0; i < this->collisions.length(); i++){
          Collision* collision = this->collisions.get(i);
          collision->step(this);
        }

        this->redraw = false;
        this->window.display();
      };
    };
  };

  void GameProcess::animateObject(Object* object) {
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
  };

  void GameProcess::addObject(Object* object) {
    this->objects.add(object);
    // this->objects.sort([](Object* one, Object* two) {
    //   return one->depth < two->depth;
    // });
  };

  Object* GameProcess::getObject(unsigned int index){
    return this->objects.get(index);
  }

  unsigned int GameProcess::getOListSize(){
    return this->objects.length();
  }

  void GameProcess::addCol(Collision* collision){
    this->collisions.add(collision);
  }

  Collision* GameProcess::getCollisionByType(string collisor){
    for(unsigned int i = 0; i < this->collisions.length(); i++){
      Collision* tempCol = this->collisions.get(i);
      if(tempCol->getType1() == collisor || tempCol->getType2() == collisor) return tempCol;
      break;
    }
  }

  unsigned short int GameProcess::getFrame() {
    return this->frame;
  };

  void GameProcess::nextFrame() {
    if(this->frame < 60) this->frame++;
    else {
      this->frame = 0;
      this->clock.restart();
    };
  };

  bool GameProcess::isRunning() {
    return this->window.isOpen();
  };

  unsigned short int GameProcess::getWindowWidth(){
    return this->width;
  }

  unsigned short int GameProcess::getWindowHeight(){
    return this->height;
  }
};