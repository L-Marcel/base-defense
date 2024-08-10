#pragma once
#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class RestartButton : public Button {
    public:
      virtual string type();
      virtual void step();
      using Button::collision;
      using Button::draw;
      using Button::free;
      ~RestartButton();

      /// @brief Cria uma instância de um botão que reinicia o jogo
      static RestartButton* create();
    protected:
      using Button::Button;
  };
};