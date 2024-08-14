#pragma once
#include <Menus/menu.hpp>

namespace Game{
  class ShopMenu : public Menu {
    public:
      virtual string type();
      virtual void step();
      using Menu::collision;
      using Menu::draw;
      using Menu::free;
      ~ShopMenu();

      /// @brief Cria uma instância do menu de pausa
      static ShopMenu* create();
      static string description;
    protected:
      /// @brief Cria uma instância do menu de pausa
      /// @param sprite_sheet página de textura do sprite do menu de pausa
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      ShopMenu(string sprite_sheet, Box box);

      Text* information = nullptr;
  };
};