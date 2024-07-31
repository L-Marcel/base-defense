#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class OptionsButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~OptionsButton();

      /// @brief Cria uma instância de um botão que vai para o menu de opções
      static OptionsButton* create();
    protected:
      using Button::Button;
  };
};