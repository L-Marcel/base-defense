#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ResumeButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~ResumeButton();

      /// @brief Cria uma instância de um botão que resume o jogo
      static ResumeButton* create();
    protected:
      using Button::Button;
  };

};