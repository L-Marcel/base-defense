#include <Engine/math.hpp>

namespace Game {
  namespace Input {
    /// @brief Retorna um vetor (x, y) que aponta um deslocamento 
    /// com base na velocidade informada e botões apertados do teclado
    /// @param left botão que indica o deslocamento para a esquerda
    /// @param top botão que indica o deslocamento para cima
    /// @param right botão que indica o deslocamento para a direita
    /// @param down botão que indica o deslocamento para baixo
    /// @param speed a velocidade do deslocamento
    /// @return o vetor (x, y)
    Vector<float> keyboard(
      Keyboard::Key left,
      Keyboard::Key top,
      Keyboard::Key right,
      Keyboard::Key down,
      float speed = 1
    );
  };
};