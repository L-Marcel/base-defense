#pragma once
#include <Menus/menu.hpp>

namespace Game{
  class ShopMenu : public Menu {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~ShopMenu();

      /// @brief Cria uma instância do menu de pausa
      static ShopMenu* create();
      static string description;
    protected:
      /// @brief Cria uma instância do menu de pausa
      /// @param spriteSheet página de textura do sprite do menu de pausa
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      ShopMenu(string spriteSheet, Box box);

      Text* information = nullptr;
  };
};