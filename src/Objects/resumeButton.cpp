#include <Objects/resumeButton.hpp>

namespace Game{
  void ResumeButton::step(){
    // Vector<float> mousePos = Mouse::position(&this->gp->window);
    // if(this->gp->checkPaused()){
    //   if(mouseEnter(mousePos)){
    //     if(Mouse::left()){
    //       this->gp->setPaused(false);
    //     }
    //   }
    // }
  };

  ResumeButton::~ResumeButton(){};

  ResumeButton* ResumeButton::create(GameProcess* gp, string sprite, Box box, bool pauseBt){
    ResumeButton* resumeButton = new ResumeButton(sprite, box);
    resumeButton->pausable = !pauseBt;
    resumeButton->buttonWidth = box.getSize().x;
    resumeButton->buttonHeight = box.getSize().y;
    resumeButton->depth = 25;
    resumeButton->subTypeVar = "ResumeButton";
    // resumeButton->gp = gp;
    // gp->objects.add(resumeButton);
    // gp->buttons.add(resumeButton);
    return resumeButton;
  };
}