#pragma once
#include <Engine/defs.hpp>

namespace Game {
  class Segment {
    public:
      Point start;
      Point end;

      /// @brief Cria o segmento de uma reta
      Segment();

      /// @brief Cria o segmento de uma reta
      /// @param start_x a coordenada x do ponto inicial
      /// @param start_y a coordenada y do ponto inicial
      /// @param end_x a coordenada x do ponto final
      /// @param end_y a coordenada y do ponto final
      Segment(float start_x, float start_y, float end_x, float end_y);

      /// @brief Cria o segmento de uma reta
      /// @param start o ponto inicial
      /// @param end o ponto final
      Segment(Point start, Point end);

      /// @brief Cria o segmento de uma reta com um único ponto
      /// @param x a coordenada x do ponto
      /// @param y a coordenada y do ponto
      Segment(float x, float y);

      /// @brief Cria o segmento de uma reta com um único ponto
      /// @param point o ponto
      Segment(Point point);

      /// @brief Cria um segmento formado pelo ponto incial e o ponto que satisfaz o comprimento máximo do segmento mas está dentro da mesma reta que o ponto final desejado
      /// @param from o ponto inicial
      /// @param to o ponto final
      /// @param max_length o comprimento máximo
      static Segment create(Point from, Point to, float max_length);

      /// @brief Diz se um determinado ponto pertence ao segmento
      /// @param x a coordenada x do ponto
      /// @param y a coordenada y do ponto
      /// @return `true` se ele pertencer, `false` caso contrário
      bool hasPoint(float x, float y) const;

      /// @brief Diz se um determinado ponto pertence ao segmento
      /// @param point o ponto
      /// @return `true` se ele pertencer, `false` caso contrário
      bool hasPoint(Point point) const;

      /// @brief Retorna o comprimento do segmento
      /// @return o comprimento
      double length();

      /// @brief Retorna o ângulo do segmento formado no plano cartesiano
      /// @return o ângulo
      double angle();

      /// @brief Obtém a extremidade do segmento mais próxima do ponto desejado
      /// @param point o ponto
      /// @return o ponto inicial do segmento, se for o mais próximo, o ponto final, caso contrário
      Point getNearestVertex(Point point);

      /// @brief Iguala um segmento a outro
      /// @param other o outro segmento
      void operator=(const Segment& other);

      /// @brief Diz se dois segmentos são iguais
      /// @param other o outro segmento
      /// @return `true` se forem, `false` caso contrário
      bool operator==(const Segment& other) const;

      /// @brief Diz se dois segmentos são diferentes
      /// @param other o outro segmento
      /// @return `true` se não forem, `false` caso contrário
      bool operator!=(const Segment& other) const;

      /// @brief Diz se um segmento intercepta o outro
      /// @param other o outro segmento
      /// @return `true` se possuirem um ou mais pontos em comum, `false` caso contrário
      bool operator&(const Segment& other) const;

      /// @brief Converte um segmento para booleano
      /// @return `true` se ele não for vazio, `false` caso contrário
      operator bool();
    private:
      bool empty = true;
  };
};