#pragma once
#include <Engine.hpp>

namespace Game {
  class Timer {
    public:
      /// @brief Inicia a contagem
      /// @param duration a duração
      void start(float duration);

      /// @brief Avança o contador
      void tick();

      /// @brief Verifica se a contagem chegou ao fim
      bool isFinished();
    protected:
      float duration;
      float time;  
  };
};