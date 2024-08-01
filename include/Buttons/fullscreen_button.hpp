#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class FullscreenButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~FullscreenButton();

      /// @brief Cria uma instância de um botão que resume o jogo
      static FullscreenButton* create();
    protected:
      using Button::Button;
  };

};