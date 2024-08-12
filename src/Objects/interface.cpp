#include <Objects/interface.hpp>

namespace Game {
  string Interface::type() {
    return "Interface";
  };

  Interface::~Interface(){};

  Interface* Interface::create() {
    Interface* interface = new Interface();
    interface->depth = 500;
    GameProcess::add(interface);

    PlayerLifeBar::create();
    BaseLifeBar::create();
    AmmoDisplay::create();
    CoinDisplay::create();

    return interface;
  };
};