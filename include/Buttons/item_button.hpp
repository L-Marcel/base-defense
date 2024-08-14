#pragma once
#include <Objects.hpp>
#include <Input.hpp>
#include <Misc/item.hpp>
#include <Sound.hpp>

namespace Game {
  class ShopMenu;
  class ItemButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~ItemButton();

      /// @brief Cria uma instância de um botão que permite comprar um item
      /// @param menu o ponteiro do menu o quanto o botão pertence
      /// @param rarity a raridade do item
      static ItemButton* create(ShopMenu* menu, unsigned short int rarity = GUARANTEED);

      Text* text = nullptr;
      Sound buy_sound = Sound("money.wav");
    protected:
      using Button::Button;
      ShopMenu* menu = nullptr;
      Item* item = nullptr;
  };
};