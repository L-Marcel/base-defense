#pragma once
#include <Objects.hpp>

namespace Game{
  class VictoryMenu : public Menu {
    public:
      virtual string type();
      using Menu::step;
      using Menu::collision;
      using Menu::draw;
      using Menu::free;
      ~VictoryMenu();

      /// @brief Cria uma instância do menu de vitória
      static VictoryMenu* create();
    protected:
      /// @brief Cria uma instância do menu de vitória
      /// @param sprite_sheet página de textura do sprite do menu de vitória
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      VictoryMenu(string sprite_sheet, Box box);
  };
};