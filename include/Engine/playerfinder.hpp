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
      /// @param direction a direção atual
      /// @param speed a velocidade atual
      /// @param range o alcance de ação
      Vector3<double> getDestiny(
        Vector<float> position, 
        double direction, 
        float speed,
        float range
      );

      /// @brief Diz se o inimigo está parado
      /// @return `true` se estiver, `false` caso contrário
      bool isStopped();

      /// @brief Diz se o inimigo está de frente para o jogador
      /// @return `true` se estiver, `false` caso contrário
      bool isFacingThePlayer();
    protected:
      bool stopped = true;
      Player* player = nullptr;
      stack<Vector<float>> paths;
      Segment current_segment;
  };
};