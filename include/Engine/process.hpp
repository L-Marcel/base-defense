#include <Engine/objects.hpp>

namespace Game {
  class GameProcess {
      private:
        unsigned short int width = 800;
        unsigned short int height = 600;
        string title = "Base Defense";
        unsigned short int frame = 0;
        Clock clock;
        bool redraw = false;
        void (*events)(Event::EventType);

      public:
        Window window = Window(VideoMode(800, 600), "Base Defense");
        List<Object> objects;

        /// @brief Cria uma instância de processo do jogo
        GameProcess();

        /// @brief Cria uma instância de processo do jogo
        /// @param width a largura da janela
        /// @param height a altura da janela
        /// @param title o título da janela
        GameProcess(
          unsigned short int width, 
          unsigned short int height,
          string title
        );
        
        /// @brief Inicia o loop do jogo
        void execute();

        /// @brief Adiciona um objeto
        /// @param object o objeto
        void addObject(Object* object);

        /// @brief Realiza a atualização do sprite do objeto, entre outras coisas
        /// @param object o objeto
        void animateObject(Object* object);

        /// @brief Retorna o frame atual do jogo
        /// @return o frame
        unsigned short int getFrame();

        /// @brief Avança o jogo para o próximo frame
        void nextFrame();

        /// @brief Diz se o jogo ainda está rodando
        /// @return verdadeiro, se estiver, falso caso contrário
        bool isRunning();

        /// @brief Recebe uma função que será chamada para todo e qualquer evento do jogo
        /// (não confundir com evento de um objeto)
        /// @param func a função a ser chamada
        void on(void (*func)(Event::EventType));
  };
};