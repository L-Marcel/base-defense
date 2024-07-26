#include <Buttons/resumeButton.hpp>

namespace Game{
  void RButton::step(){};

  RButton::~ResumeButton(){};

  RButton* RButton::create(GameProcess* gp, string sprite, Box box, bool pauseBt){
    RButton* resumeButton = new RButton(sprite, box);
    resumeButton->pausable = !pauseBt;
    resumeButton->rectangleWidth = box.getSize().x;
    resumeButton->rectangleHeight = box.getSize().y;
    resumeButton->gp = gp;
    gp->objects.add(resumeButton);
    return resumeButton;
  };
}