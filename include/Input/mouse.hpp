#pragma once
#include <Engine/math.hpp>

namespace Game {
  class Mouse {
    protected:
      static vector<MouseButton> down;
      static vector<MouseButton> pressed;
      static vector<MouseButton> released;
    public:
      /// @brief Atualiza o estado dos botões do mouse
      static void update();

      /// @brief Retorna a posição do mouse na janela do jogo
      /// @return o ponto indicando a posição do mouse
      static Point position();

      /// @brief Pressiona um botão do mouse
      /// @param button o botão do mouse
      static void press(MouseButton button);

      /// @brief solto um botão do mouse
      /// @param button o botão do mouse
      static void release(MouseButton button);

      /// @brief Diz se um botão do mouse está pressionada
      /// @param button o botão do mouse
      /// @return `true` se estiver, `false` caso contrário
      static bool isDown(MouseButton button);

      /// @brief Diz se um botão do mouse foi pressionada neste frame
      /// @param button o botão do mouse
      /// @return `true` se foi, `false` caso contrário
      static bool isPressed(MouseButton button);

      /// @brief Diz se um botão do mouse foi solto neste frame
      /// @param button o botão do mouse
      /// @return `true` se foi, `false` caso contrário
      static bool isReleased(MouseButton button);

      /// @brief Diz se o botão esquerdo do mouse foi pressionado neste frame
      /// @return `true` se foi, `false` caso contrário
      static bool isLeftPressed();

      /// @brief Diz se o botão esquerdo do mouse foi solto neste frame
      /// @return `true` se foi, `false` caso contrário
      static bool isLeftReleased();

      /// @brief Diz se o botão esquerdo do mouse está pressionado
      /// @return `true` se estiver, `false` caso contrário
      static bool isLeftDown();

      /// @brief Diz se o botão direito do mouse foi pressionado neste frame
      /// @return `true` se foi, `false` caso contrário
      static bool isRightPressed();

      /// @brief Diz se o botão direito do mouse foi solto neste frame
      /// @return `true` se foi, `false` caso contrário
      static bool isRightReleased();

      /// @brief Diz se o botão direito do mouse está pressionado
      /// @return `true` se estiver, `false` caso contrário
      static bool isRightDown();
  };
};