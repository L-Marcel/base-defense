#include <Buttons.hpp>

namespace Game{
  string ResumeButton::type() {
    return "ResumeButton";
  };

  void ResumeButton::step() {
    this->visible = GameProcess::paused;

    if(GameProcess::paused && this->isMouseHovering() && Mouse::isLeftReleased()) {
      GameProcess::paused = false;
    };
  };

  ResumeButton::~ResumeButton() {};

  ResumeButton* ResumeButton::create() {
    ResumeButton* resumeButton = new ResumeButton("resume_button.png", Box(51.5, 15, 103, 30));
    resumeButton->pausable = false;
    resumeButton->buttonWidth = 103;
    resumeButton->buttonHeight = 30;
    resumeButton->depth = 500;
    resumeButton->position = CENTER;
    resumeButton->position.y = 150;
    resumeButton->scale(3);

    GameProcess::add(resumeButton);
    return resumeButton;
  };
}