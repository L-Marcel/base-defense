#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class Button : public Object2D{
    public:
      virtual string type();
      void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Button();

      static Button* create(GameProcess* gp, string sprite, Box box, bool pauseBt);

    protected:
      Button();
      Button(string spriteSheet, Box box);
      unsigned short int buttonWidth;
      unsigned short int buttonHeight;
  };
}