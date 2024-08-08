#pragma once
#include <Engine/math.hpp>
#include <Objects/player.hpp>

namespace Game {
  class Playerfinder {
    public:
      /// @brief Cria um desbravador para os inimigos
      Playerfinder();

      /// @brief Retorna a posição do inimigo no próximo frame e sua direção
      /// @param position a posição atual
      /// @param speed a velocidade atual
      /// @param range o alcance de ação
      Segment getPath(
        Point position, 
        float speed,
        float range
      );

      /// @brief Diz em qual setor o inimigo está, os setores são as 9 regiões do mapa
      /// @param position a posição atual
      /// @return O identificador do setor
      unsigned short int getSector(Point position);

      /// @brief Diz se o inimigo está parado
      /// @return `true` se estiver, `false` caso contrário
      bool isStopped();

      /// @brief Diz se o inimigo está de frente para o jogador
      /// @return `true` se estiver, `false` caso contrário
      bool isFacingPlayer(Point position);

      /// Limites dos setores =====================
      const static Segment rab;
      const static Segment rbc;
      const static Segment rcd;
      const static Segment rda;
      const static Segment ab;
      const static Segment bc;
      const static Segment cd;
      const static Segment da;
      /// =========================================
    protected:
      bool stopped = true;
      Segment path;
  };
};