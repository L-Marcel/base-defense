#pragma once
#include <Engine/math.hpp>

namespace Game {
  class Pathfinder {
    public:
      /// @brief Cria uma instância do desbravador
      Pathfinder();
      
      /// @brief Monta o caminho a ser seguido com base no destino
      /// @param position a posição atual
      /// @param speed a velocidade de movimentação
      /// @return Um segmento que começa na posição atual e termina na próxima posição
      Segment getPath(Point position, float speed);
      
      /// @brief Define o destino do desbravador
      /// @param position o destino
      void setDestiny(Point position);

      /// @brief Diz se o desbravador já chegou ao destino
      /// @return `true` se já chegou ao destino, `false` caso contrário
      bool isStopped();
    protected:
      stack<Point> paths;
      Segment current_segment;

      /// @brief Obtém os segmentos da torre mais próxima da posição atual
      /// @param position a posição atual
      /// @return Os quatro segmentos da torre mais próxima
      Vector4<Segment> getNearestSegments(Point position);
  };
};