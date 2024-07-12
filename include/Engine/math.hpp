#pragma once
#include <Engine/base.hpp>

namespace Game {
  class Math {
    public:
      /// @brief Retorna um ponto nos limites da circunferência de um círculo
      /// @param radious o raio do círculo
      /// @param angle o ângulo
      /// @return o par de coordenadas do ponto
      static Vector<float> pointInRadius(double radious, double angle);

      /// @brief Retorna o arco tangente da reta que passa entre o ponto (0,0)
      /// e o ponto formado pelas coordenadas (x, y)
      /// @param x a coordenada do eixo x
      /// @param y a coordenada do eixo y
      /// @return o arco tangente da reta
      static double pointDirection(float x, float y);
  };
};