#pragma once
#include <Engine/list.hpp>

namespace Game {
  class Input {
    protected:
      static vector<Key> down;
      static vector<Key> pressed;
      static vector<Key> released;
    public:
      /// @brief Atualiza o estado das teclas
      static void update();

      /// @brief Pressiona uma tecla
      /// @param key a tecla
      static void press(Key key);

      /// @brief Solta uma tecla
      /// @param key a tecla
      static void release(Key key);

      /// @brief Diz se uma tecla está pressionada
      /// @param key a tecla
      /// @return `true` se estiver, `false` caso contrário
      static bool isDown(Key key);

      /// @brief Diz se uma tecla foi pressionada neste frame
      /// @param key a tecla
      /// @return `true` se foi, `false` caso contrário
      static bool isPressed(Key key);

      /// @brief Diz se uma tecla foi solta neste frame
      /// @param key a tecla
      /// @return `true` se foi, `false` caso contrário
      static bool isReleased(Key key);
  };
};