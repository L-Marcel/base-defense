#include <Engine.hpp>

namespace Game {
  class Music : protected sf::Music {
    public:
      /// @brief Cria uma instância de uma música
      /// @param filename o arquivo da música 
      Music(string filename);
  };
}