#include <Objects.hpp>
#include <Input.hpp>
#include <Objects/text.hpp>

namespace Game{
  class Text;
  class Button : public Object2D{
    public:
      virtual string type();
      virtual string subType();
      virtual void setSubType(string newSubType);
      virtual void step();
      virtual void draw();
      using Object2D::free;
      virtual ~Button();

      static Button* create(GameProcess* gp, string sprite, Box box, bool pauseBt);

      bool getClicked();

      void setClicked(bool clicked);

      bool wasBridged();

      void setBridged(bool bridged);

      void setText(string content);

    protected:
      Button();
      Button(string spriteSheet, Box box);
      string subTypeVar;
      unsigned short int buttonWidth;
      unsigned short int buttonHeight;
      bool isClicked = false;
      bool bridged = false;
      Text* buttonText = nullptr;
  };
}