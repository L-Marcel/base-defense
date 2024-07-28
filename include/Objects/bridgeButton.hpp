#include <Objects.hpp>
#include <Input.hpp>
#include <Engine/list.hpp>

namespace Game{
  class BridgeButton : public Button{
    public:
      void step();
      using Button::draw;
      virtual ~BridgeButton();

      static BridgeButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt, string initialSubType);

      void addType(string subType);

    protected:
      using Button::Button;
      vector<string> bridgeTypes;
  };
}