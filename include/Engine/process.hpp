#pragma once
#include <Engine/collision.hpp>
#include <Objects.hpp>

namespace Game {
  class GameProcess {
    protected:
      static GameProcess* gp;
      List<Object> queueFree;
      List<Object> objects;
      Window window = Window(VideoMode(1280, 720), "Base Defense");
      //View view = View(sf::FloatRect(0, 0, this->width, this->height));
      List<Button> buttons;
      unsigned short int frame = 0;
    private:
      Clock clock;
      bool isPaused = false;
    public:
      /// @brief Cria uma instância de processo do jogo
      GameProcess();

      /// @brief Destroy uma instância de processo do jogo
      ~GameProcess();

      void adjustView(Window* window, View* view);
      
      /// @brief Inicia o loop do jogo
      void execute();

      /// @brief Reordenada a ordem dos objetos com base no `depth` de cada um
      void sort();

      /// @brief Avança o jogo para o próximo frame
      void nextFrame();

      /// @brief Diz se o jogo ainda está rodando
      /// @return verdadeiro, se estiver, falso caso contrário
      bool isRunning();

      /// @brief Adiciona um objeto ao jogo
      /// @param object o ponteiro do objeto
      static void add(Object* object);

      /// @brief Coloca um objeto na fila de remoção do jogo
      /// @param object o ponteiro do objeto
      static void destroy(Object* object);

      /// @brief Diz quantos objetos tem no jogo
      /// @return o número de objetos
      static unsigned short int length();

      /// @brief Obtém um objeto do jogo
      /// @param index o índice desse objeto
      /// @return o ponteiro para o objeto obtído
      static Object* get(unsigned short int index);

      /// @brief Desenha algo em tela
      /// @param drawable algo desenhável
      static void draw(const Drawable& drawable);

      /// @brief Obtém a janela do processo do jogo
      /// @return a janela
      static const Window& getWindow();

      /// @brief Retorna o frame atual do jogo
      /// @return o frame
      static unsigned short int getFrame();

      /// @brief Realiza a atualização do sprite do objeto, entre outras coisas
      /// @param object o objeto
      static void animate(Object2D* object);

      /// @brief Retorna se o jogo está pausado
      /// @return se o jogo está pausado
      bool checkPaused();

      /// @brief Define se o jogo ta pausado
      /// @param pause 
      void setPaused(bool pause);

      /// @brief Muda as dimensões da window
      /// @param newWidth nova largura
      /// @param newHeight nova altura
      void resizeWindow(unsigned int newWidth, unsigned int newHeight);
  };
};