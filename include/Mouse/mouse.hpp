#include "../Engine/math.hpp"

namespace lm {
  namespace Mouse {
    /// @brief Retorna a posição do mouse no monitor ou na janela do jogo
    /// (caso informe a janela)
    /// @param window a janela do jogo
    /// @return o vetor (x, y) indicando a posição do mouse
    Vector<float> position(Window* window = nullptr);

    /// @brief Diz se o botão esquerdo do mouse foi apertado
    /// @return verdadeiro, caso tenha sido
    bool left();

    /// @brief Diz se o botão direito do mouse foi apertado
    /// @return verdadeiro, caso tenha sido
    bool right();

    /// @brief Diz se o botão do meio do mouse foi apertado
    /// @return verdadeiro, caso tenha sido
    bool middle();

    /// @brief Diz se o botão extra do mouse foi apertado
    /// @return verdadeiro, caso tenha sido
    bool extra1();

    /// @brief Diz se o segundo botão extra do mouse foi apertado
    /// @return verdadeiro, caso tenha sido
    bool extra2();
  };
};