#include "rooms.hpp"

namespace lm {
  class GameProcess {
      private:
        unsigned short int width = 800;
        unsigned short int height = 600;
        string title = "L-Marcel's Game Engine";
        unsigned short int frame = 0;
        Clock clock;
        unsigned int room = 0;
        bool redraw = false;
        void (*events)(Event::EventType);

      public:
        Window window = Window(VideoMode(800, 600), "L-Marcel's Game Engine");
        List<Room> rooms;
        bool running = true;

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

        /// @brief Adiciona uma sala ao jogo
        /// @param room o ponteiro da sala
        /// @return o id da sala no jogo
        unsigned int addRoom(Room* room);

        /// @brief Inicia o loop do jogo
        void execute();

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