#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ItemButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~ItemButton();

      /// @brief Cria uma instância de um botão que resume o jogo
      /// @param item o item
      static ItemButton* create(unsigned short int item);

      function<void()> action = [](){};
      short int rarity = 0;
      wstring description = L"";
    protected:
      using Button::Button;
  };

};