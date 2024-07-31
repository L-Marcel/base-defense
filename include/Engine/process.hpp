#pragma once
#include <Engine/collision.hpp>
#include <Objects.hpp>

namespace Game {
  class 
  GameProcess {
    protected:
      static GameProcess* gp;
      List<Object> queueFree;
      List<Object> objects;
      unsigned int frame_instances_amount = 0;
      Menu* menu = nullptr;
      Window window = Window(VideoMode(1280, 720), "Base Defense");
      View view = View(Point(0, 0), Resolution(1280, 720));
      unsigned short int frame = 0;
      bool paused = false;
    private:
      Clock clock;
    public:
      static void close();
      static void pause();
      static void resume();
      static void navigate(Menu* menu = nullptr);
      static void setResolution(Resolution resolution);

      /// @brief Cria uma instância de processo do jogo
      GameProcess();

      /// @brief Destroy uma instância de processo do jogo
      ~GameProcess();
      
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
  };
};