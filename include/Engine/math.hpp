#pragma once
#include <Misc/segment.hpp>

namespace Game {
  namespace Math {
    /// @brief Retorna um ponto nos limites da circunferência de um círculo
    /// @param radius o raio do círculo
    /// @param angle o ângulo
    /// @return o par de coordenadas do ponto
    Point pointInRadius(double radius, double angle);

    /// @brief Retorna o arco tangente da reta que passa entre o ponto (0,0)
    /// e o ponto formado pelas coordenadas (x, y)
    /// @param x a coordenada do eixo x
    /// @param y a coordenada do eixo y
    /// @return o arco tangente da reta
    double pointDirection(float x, float y);

    /// @brief Retorna o arco tangente da reta que passa entre o ponto (0,0)
    /// e o ponto formado pelas coordenadas (x, y)
    /// @param point a coordenada do ponto
    /// @return o arco tangente da reta
    double pointDirection(Point point);

    /// @brief Retorna a distância entre dois pontos
    /// @param a o primeiro ponto
    /// @param b o segundo ponto
    /// @return a distância
    double pointDistance(Point a, Point b = Point(0, 0));
  };
};