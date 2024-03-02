#include "../include/lm.h"

namespace lm {
  GameProcess::GameProcess() {
    this->redraw = true;
    this->window.setFramerateLimit(60);
    this->events = [](Event::EventType ev) {};
  };

  GameProcess::GameProcess(
    unsigned short int width = 800,
    unsigned short int height = 600,
    string title = "L-Marcel's Game Engine"
  ) {
    this->title = title;
    this->width = width;
    this->height = height;

    this->window.setSize(Vector2u(width, height));
    this->window.setTitle(title);
    this->redraw = true;
    this->window.setFramerateLimit(60);
    this->events = [](Event::EventType ev) {};
  };

  void GameProcess::on(void (*func)(Event::EventType)) {
    this->events = func;
  };

  unsigned int GameProcess::addRoom(Room* room) {
    room->defineId(&this->rooms);
    this->rooms.push(room);
    if(this->room <= 0) this->room = room->getId();
    return room->getId();
  };

  void GameProcess::step() {
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
        
        if(this->room > 0) {
          RoomType* currentRoom = this->rooms.find(this->room);

          if(currentRoom != NULL) {
            currentRoom->step(this, &this->window, this->frame);
          };
        };

        this->redraw = false;
        this->window.display();
      };
    };
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