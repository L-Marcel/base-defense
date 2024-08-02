#pragma once
#include <Engine.hpp>

namespace Game {
  class Timer {
    public:
      /// @brief Define a duração da contagem
      /// @param duration a duração
      void setDuration(float duration);

      /// @brief Inicia e realiza a contagem pelo tempo determinado
      void start();

      /// @brief Verifica se a contagem chegou ao fim
      bool isFinished();
    protected:
      float duration;
      float time;  
  };
};