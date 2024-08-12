#pragma once
#include <Objects.hpp>

namespace Game{
  class PauseMenu : public Menu {
    public:
      virtual string type();
      using Menu::step;
      using Menu::collision;
      using Menu::draw;
      using Menu::free;
      ~PauseMenu();

      /// @brief Cria uma instância do menu de pausa
      static PauseMenu* create();
    protected:
      /// @brief Cria uma instância do menu de pausa
      /// @param sprite_sheet página de textura do sprite do menu de pausa
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      PauseMenu(string sprite_sheet, Box box);
  };
};