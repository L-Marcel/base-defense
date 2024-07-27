#include <Objects/resolutionButton.hpp>

namespace Game{
  void ResolutionButton::step(){
    Vector<float> mousePos = Mouse::position(&this->gp->window);
    if(this->gp->checkPaused()){
      this->visible = true;
      if(mousePos.x <= (this->position.x + this->buttonWidth) &&
        mousePos.x >= (this->position.x - this->buttonWidth) &&
        mousePos.y <= (this->position.y + this->buttonHeight) &&
        mousePos.y >= (this->position.y - this->buttonHeight))
        {
          if(Mouse::left()){
            this->gp->window.setSize(this->resolutionSize);
            this->gp->resizeWindow(this->resolutionSize.x, this->resolutionSize.y);
            this->gp->view.setSize(this->resolutionSizeF.x, this->resolutionSizeF.y);
            this->gp->view.setCenter(resolutionSizeF.x/2.f, resolutionSizeF.y/2.f);
          }
      }
    } else{
      this->visible = false;
    }
  };

  ResolutionButton::~ResolutionButton(){};

  ResolutionButton* ResolutionButton::create(GameProcess* gp, string sprite, Box box, bool pauseBt, unsigned int expectedWidth, unsigned int expectedHeigth){
    ResolutionButton* resolButton = new ResolutionButton(sprite, box);
    resolButton->pausable = !pauseBt;
    resolButton->buttonWidth = box.getSize().x;
    resolButton->buttonHeight = box.getSize().y;
    resolButton->resolutionSize.x = expectedWidth;
    resolButton->resolutionSize.y = expectedHeigth;
    resolButton->resolutionSizeF.x = (float)expectedWidth;
    resolButton->resolutionSizeF.y = (float)expectedHeigth;
    resolButton->gp = gp;
    gp->objects.add(resolButton);
    return resolButton;
  }
}