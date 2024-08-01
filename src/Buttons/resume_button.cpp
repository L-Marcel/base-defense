#include <Buttons.hpp>

namespace Game{
  string ResumeButton::type() {
    return "ResumeButton";
  };

  void ResumeButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::resume();
    } else this->animate(1, 1, 0, false);
  };

  ResumeButton::~ResumeButton() {};

  ResumeButton* ResumeButton::create() {
    ResumeButton* resumeButton = new ResumeButton("resume_button.png", Box(53, 16, 106, 32));
    resumeButton->animate(1, 1, 0, false);
    resumeButton->pausable = false;
    resumeButton->depth = 500;
    resumeButton->position = CENTER;
    resumeButton->scale(3);

    GameProcess::add(resumeButton);
    return resumeButton;
  };
};