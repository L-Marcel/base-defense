#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ResumeButton : public Button{
    public:
      void step();
      using Button::draw;
      virtual ~ResumeButton();

      /// @brief Cria uma instância de um botão de resume (sair do pause)
      /// @param gp ponteiro do processo do jogo
      /// @param sprite sprite do botão
      /// @param box caixa que informa a origem e tamanho do sprite
      /// @param pauseBt se é um botão de tela de pause
      /// @return uma instância de um botão de resume
      static ResumeButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt);

    protected:
      using Button::Button;
  };

};