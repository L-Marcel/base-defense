#include <Objects/button.hpp>

namespace Game{
  void Button::step(){
    Vector<float> mousePos = Mouse::position(&this->gp->window);
    if(gp->checkPaused() &&
       mousePos.x <= (this->position.x+(this->buttonWidth/2 * this->sprite->getScale().x)) &&
       mousePos.x >= (this->position.x-(this->buttonWidth/2 * this->sprite->getScale().x)) &&
       mousePos.y <= (this->position.y+(this->buttonHeight/2 * this->sprite->getScale().y)) &&
       mousePos.y >= (this->position.y-(this->buttonHeight/2 * this->sprite->getScale().y))){
      cout << "Pausado e mouse no botão" << endl;
      if(Mouse::left()){
        gp->setPaused(false);
      }
    }
  };

  string Button::type(){
    return "Button";
  }

  Button::~Button(){};

  Button* Button::create(GameProcess* gp, string sprite, Box box, bool pauseBt){
    Button* button = new Button(sprite, box);
    button->pauseButton = pauseBt;
    button->buttonWidth = box.getSize().x;
    button->buttonHeight = box.getSize().y;
    button->gp = gp;
    gp->objects.add(button);
    return button;
  };
}