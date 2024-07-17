#include <Engine.hpp>

namespace Game {
  class Sound : public sf::Sound {
    public:
      Sound(string filename);
      ~Sound();
  };
}