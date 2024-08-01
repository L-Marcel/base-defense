#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class CloseButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~CloseButton();

      /// @brief Cria uma instância de um botão que fecha o jogo
      static CloseButton* create();
    protected:
      using Button::Button;
  };
};