#include <Engine.hpp>

namespace Game {
  class Music : public sf::Music {
    public:
      Music(string filename);
      ~Music();
  };
}