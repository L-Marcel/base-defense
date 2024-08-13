#pragma once
#include <Objects.hpp>

namespace Game{
  class ResolutionMenu : public Menu {
    public:
      virtual string type();
      using Menu::step;
      using Menu::collision;
      using Menu::draw;
      using Menu::free;
      ~ResolutionMenu();

      /// @brief Cria uma instância do menu de pausa
      static ResolutionMenu* create();
    protected:
      /// @brief Cria uma instância do menu de pausa
      /// @param sprite_sheet página de textura do sprite do menu de pausa
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      ResolutionMenu(string sprite_sheet, Box box);
  };
};