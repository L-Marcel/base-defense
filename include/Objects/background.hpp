#pragma once
#include <Objects.hpp>

namespace Game {
  class Background : public Object2D {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Background();

      /// @brief Cria uma instância do plano de fundo do jogo
      static Background* create();
    protected:
      /// @brief Cria uma instância do plano de fundo
      /// @param sprite_sheet página de textura do sprite do plano de fundo
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Background(string sprite_sheet, Box box);
  };
};