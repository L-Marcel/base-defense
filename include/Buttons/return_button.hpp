#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class Menu;
  class ReturnButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~ReturnButton();

      /// @brief Cria uma instância de um botão que fecha o jogo
      /// @param create_previous_menu a função que criará o menu anterior
      static ReturnButton* create(function<Menu*()> create_previous_menu = []() { return nullptr; });

      function<Menu*()> create_previous_menu = []() { return nullptr; };
    protected:
      using Button::Button;
      Menu* menu = nullptr;
  };

};