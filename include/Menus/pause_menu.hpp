#pragma once
#include <Objects.hpp>

namespace Game{
  class PauseMenu : public Menu {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~PauseMenu();

      /// @brief Cria uma instância do menu de pausa
      static PauseMenu* create();
    protected:
      /// @brief Cria uma instância do menu de pausa
      /// @param spriteSheet página de textura do sprite do menu de pausa
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      PauseMenu(string spriteSheet, Box box);
  };
};