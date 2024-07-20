#include <Engine.hpp>

namespace Game {
  class Sound : public sf::Sound {
    public:
      /// @brief Cria uma instância de um som
      /// @param filename o arquivo do som 
      Sound(string filename);
      ~Sound();
  };
}