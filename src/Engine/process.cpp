#include <Engine.hpp>

namespace Game {
  GameProcess::~GameProcess() {
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
      object->free();
    };
  };

  GameProcess::GameProcess() {
    this->redraw = true;
    this->window.setFramerateLimit(60);
    this->window.setSize(Vector<unsigned int>(this->width, this->height));
    this->window.setTitle(this->title);
  };

  void GameProcess::execute() {
    unsigned int number_of_instances = 0;
    while(this->isRunning()) {
      Time elapsed = this->clock.getElapsedTime();

      if((this->frame)/60 <= elapsed.asSeconds()) {
        this->nextFrame();
        this->redraw = true;
      };

      Event event;
      while(window.pollEvent(event)) {
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

        if(this->objects.length() != number_of_instances) {
          this->sort();
          number_of_instances = this->objects.length();
        };

        for(unsigned int i = 0; i < number_of_instances; i++) {
          Object* object = this->objects.get(i);
          object->collision();
          object->step();
          object->draw();
        };

        this->window.display();

        for(unsigned int i = 0; i < this->queue_free.length(); i++) {
          Object* object = this->queue_free.get(i);
          this->objects.remove(object);
          this->queue_free.remove(i);
          object->free();
        };

        this->redraw = false;
      };
    };

    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Object* object = this->objects.get(i);
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
};