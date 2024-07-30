#include <Objects/resolutionButton.hpp>

namespace Game{
  void ResolutionButton::step(){
    Vector<float> mousePos = Mouse::position(&this->gp->window);
    if(this->gp->checkPaused() && this->isVisible()){
      if(mouseEnter(mousePos)){
        if(Mouse::left()){
          this->gp->window.setSize(this->resolutionSize);
          this->gp->resizeWindow(this->resolutionSize.x, this->resolutionSize.y);
          this->gp->view.setSize(this->resolutionSizeF.x, this->resolutionSizeF.y);
          this->gp->view.setCenter(resolutionSizeF.x/2.f, resolutionSizeF.y/2.f);
        }
      }
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
    resolButton->depth = 25;
    resolButton->subTypeVar = "ResolutionButton";
    resolButton->gp = gp;
    gp->objects.add(resolButton);
    gp->buttons.add(resolButton);
    return resolButton;
  }
}