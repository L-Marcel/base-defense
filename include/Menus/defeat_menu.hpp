#pragma once
#include <Objects.hpp>

namespace Game{
  class DefeatMenu : public Menu {
    public:
      virtual string type();
      using Menu::step;
      using Menu::collision;
      using Menu::draw;
      using Menu::free;
      ~DefeatMenu();

      /// @brief Cria uma instância do menu de derrota
      static DefeatMenu* create();
    protected:
      /// @brief Cria uma instância do menu de derrota
      /// @param sprite_sheet página de textura do sprite do menu de derrota
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      DefeatMenu(string sprite_sheet, Box box);
  };
};