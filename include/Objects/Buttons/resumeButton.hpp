#include <Objects/object_2d.hpp>
#include <Objects/button.hpp>
#include <Input.hpp>

namespace Game{
  class ResumeButton : public Button{
    public:
      void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~ResumeButton();

      static RButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt);

    protected:
      using Button::Button;
      unsigned short int buttonWidth;
      unsigned short int buttonHeight;
  } typedef RButton;

};