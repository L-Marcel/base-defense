#include <Game.hpp>

namespace Game {
  GameProcess* GameProcess::gp = nullptr;

  unsigned int GameProcess::money = 30;
  Sound GameProcess::open_sound = Sound("open.ogg");
  Sound GameProcess::click_sound = Sound("click.ogg");
  Music GameProcess::theme_music = Music("default.ogg");
 
  void GameProcess::execute() {
    this->restart();

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

      bool pause_requested = Input::isPressed(Keyboard::Escape);
      if(
        pause_requested && this->paused && 
        (this->in("PauseMenu") || this->in("ResolutionMenu"))
      ) this->resume();
      else if(pause_requested && this->menu == nullptr) this->pause();
      
      if(this->paused && GameProcess::theme_music.getStatus() != Music::Paused)
        GameProcess::theme_music.pause();
      else if(!this->paused && GameProcess::theme_music.getStatus() == Music::Paused)
        GameProcess::theme_music.play();
      Input::update();
      Mouse::update();
    };

    this->clear();
  };

  void GameProcess::clear() {
    this->restarted = true;
    this->menu = nullptr;
    this->queue_free.clear();

    while(this->objects.length() > 0) {
      Object* object = this->objects.get(0);
      this->objects.remove(object);
      object->free();
    };
  };

  bool GameProcess::isRunning() {
    return this->window.isOpen();
  };

  void GameProcess::nextFrame() {
    if(this->restarted && this->objects.length() == 0) {
      Background::create();
      Spawn::create();
      Base::create();
      Player::create();
      Interface::create();
      this->restarted = false;
    };

    if(this->frame < 60) this->frame++;
    else {
      this->frame = 0;
      this->clock.restart();
    };

    this->window.clear();

    if(this->frame_instances_amount != this->objects.length() || !this->objects.isSorted()) {
      GameProcess::sort();
      this->frame_instances_amount = this->objects.length();
    };

    for(unsigned int i = 0; i < this->frame_instances_amount; i++) {
      Object* object = this->objects.get(i);

      if(!object->isPausable()) object->step();
      else if(!this->paused) {
        object->collision();
        object->step();
      };

      if(this->restarted) return;
      if(object->visible) object->draw();
    };

    this->window.display();

    for(unsigned int i = 0; i < this->queue_free.length(); i++) {
      Object* object = this->queue_free.get(i);
      this->objects.remove(object);
      object->free();
    };

    this->queue_free.clear();
  };

  GameProcess::~GameProcess() {
    Sprites::clear();
    this->clear();
    this->gp = nullptr;
  };

  GameProcess::GameProcess() {
    if(this->gp != nullptr) {
      delete this->gp;
    };

    srand(time(NULL));
    this->gp = this;
    this->window.setFramerateLimit(60);

    GameProcess::theme_music.setVolume(30);
    GameProcess::theme_music.play();
  };
};