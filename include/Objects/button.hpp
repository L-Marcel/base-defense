#include <Objects.hpp>
#include <Input.hpp>
#include <Objects/text.hpp>

namespace Game{
  class Text;
  class Button : public Object2D{
    public:
      virtual string type();
      virtual string subType();
      virtual void setSubType(string newSubType);
      virtual void step();
      virtual void draw();
      using Object2D::free;
      virtual ~Button();

      /// @brief Cria uma instância de um botão
      /// @param sprite sprite do botão
      /// @param box caixa que informa a origem e tamanho do sprite
      /// @param pauseBt se é um botão de tela de pause
      /// @return uma instância de um botão
      static Button* create(string sprite, Box box, bool pauseBt);

      /// @brief Retorna se o botão foi clicado ou não
      /// @return se o botão foi clicado ou não
      bool getClicked();

      /// @brief Muda a variável isClicked da classe
      /// @param clicked 
      void setClicked(bool clicked);

      /// @brief Retorna se o botão já foi "ponte'ado" (se um BridgeButton já fez a ponte para esse botão)
      /// @return se o botão já foi "ponte'ado"
      bool wasBridged();

      /// @brief Muda a variável bridged da classe
      /// @param bridged 
      void setBridged(bool bridged);

      /// @brief Cria um texto para o botão
      /// @param content o texto que será impresso
      /// @param size o tamanho do texto
      void setText(string content, unsigned int size);

      /// @brief Pega o texto do botão
      /// @return o texto do botão, caso ele exista, caso contrário ele retorna nullptr
      Text* getText();

      /// @brief Retorna se o mouse entrou no botão
      /// @param mousePosition posição do mouse
      /// @return se o mouse entrou no botão
      bool mouseEnter(Vector<float> mousePosition);
    protected:
      Button();
      Button(string spriteSheet, Box box);
      string subTypeVar;
      unsigned short int buttonWidth;
      unsigned short int buttonHeight;
      bool isClicked = false;
      bool bridged = false;
      Text* buttonText = nullptr;
  };
}