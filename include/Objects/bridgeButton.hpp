#include <Objects.hpp>
#include <Input.hpp>
#include <Engine/list.hpp>

namespace Game{
  class BridgeButton : public Button{
    public:
      void step();
      using Button::draw;
      virtual ~BridgeButton();

      /// @brief Cria uma instância de um botão de ponte (que fará outros botões aparecerem/funcionarem)
      /// @param gp ponteiro do processo do jogo
      /// @param sprite sprite do botão
      /// @param box caixa que informa a origem e tamanho do sprite
      /// @param pauseBt se é um botão de tela de pause
      /// @param initialSubType subtipo do botão
      /// @return uma instância de um botão de ponte
      static BridgeButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt, string initialSubType);

      void addType(string subType);

    protected:
      using Button::Button;
      vector<string> bridgeTypes;
  };
}