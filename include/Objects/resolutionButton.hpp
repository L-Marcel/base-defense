#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ResolutionButton : public Button{
    public:
      void step();
      virtual ~ResolutionButton();

      static ResolutionButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt, unsigned int expectedWidth, unsigned int expectedHeigth);

    protected:
      Vector<unsigned int> resolutionSize;
      Vector<float> resolutionSizeF;
      using Button::Button;
  };
}