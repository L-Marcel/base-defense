#pragma once
#include <Engine/math.hpp>

namespace Game {
  namespace Input {
    /// @brief Diz se o jogador está tentando atirar ou não
    /// @return `true` se o jogador estiver tentando, `false` caso contrário
    bool fire(
      Keyboard::Key q = Keyboard::Key::Q
    );
  };
};