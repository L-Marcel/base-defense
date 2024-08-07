#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Sprites {
    protected:
      static map<string, Sprite*> loaded;
    public:
      /// @brief Carrega uma folha de textura
      /// @param filename o nome do arquivo da folha
      /// @return o ponteiro para a textura
      static Sprite* load(string filename, Box box);

      /// @brief Limpa todas as texturas da memória
      static void clear();
  };
};