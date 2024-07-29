#pragma once
#include <Engine/math.hpp>
#include <Objects/player.hpp>
#include <stack>

namespace Game {
  class Playerfinder {
    public:
      /// @brief Cria uma instância do "desbravador" do jogador
      Playerfinder(Player* player);
      Playerfinder();

      /// @brief Retorna a posição do inimigo no próximo frame e sua direção
      /// @param position a posição atual
      /// @param speed a velocidade atual
      /// @param range o alcance de ação
      Segment getDestiny(
        Point position, 
        float speed,
        float range
      );

      unsigned short int getSector(Point position);

      /// @brief Diz se o inimigo está parado
      /// @return `true` se estiver, `false` caso contrário
      bool isStopped();

      /// @brief Diz se o inimigo está de frente para o jogador
      /// @return `true` se estiver, `false` caso contrário
      bool isFacingPlayer(Point position);

      Segment rab;
      Segment rbc;
      Segment rcd;
      Segment rda;
    protected:
      bool stopped = true;
      Player* player = nullptr;
      Segment path;
      Segment ab;
      Segment bc;
      Segment cd;
      Segment da;
  };
};