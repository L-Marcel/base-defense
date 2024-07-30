#pragma once
#include <Engine/math.hpp>

namespace Game {
  namespace Mouse {
    /// @brief Retorna a posição do mouse na janela do jogo
    /// @return o ponto indicando a posição do mouse
    Point position();

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