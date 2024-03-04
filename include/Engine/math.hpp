#include "base.hpp"

namespace lm {
  /// @brief Retorna um ponto nos limites da circunferência de um círculo
  /// @param radious o raio do círculo
  /// @param angle o ângulo
  /// @return o par de coordenadas do ponto
  Coord pointInRadious(double radious, double angle);

  /// @brief Retorna o arco tangente da reta que passa entre o ponto (0,0)
  /// e o ponto formado pelas coordenadas (x, y)
  /// @param x a coordenada do eixo x
  /// @param y a coordenada do eixo y
  /// @return 
  double pointDirection(float x, float y);
};