#include <Buttons.hpp>

namespace Game{
  string ResumeButton::type() {
    return "ResumeButton";
  };

  void ResumeButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::resume();
    } else this->animate(1, 1, 0, false);
  };

  ResumeButton::~ResumeButton() {};

  ResumeButton* ResumeButton::create() {
    ResumeButton* resume_button = new ResumeButton("resume_button.png", Box(53, 16, 106, 32));
    resume_button->animate(1, 1, 0, false);
    resume_button->pausable = false;
    resume_button->depth = 500;
    resume_button->position = CENTER;
    resume_button->scale(3);

    GameProcess::add(resume_button);
    return resume_button;
  };
};