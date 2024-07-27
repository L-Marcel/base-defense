#include <Engine/collision.hpp>
#include <Objects.hpp>

namespace Game {
  class GameProcess {
    private:
      unsigned short int width = 1280;
      unsigned short int height = 720;
      string title = "Base Defense";
      unsigned short int frame = 0;
      Clock clock;
      bool redraw = false;
      bool isPaused = false;
    public:
      Window window = Window(VideoMode(1280, 720), "Base Defense");
      View view = View(sf::FloatRect(0, 0, this->width, this->height));
      List<Object> objects;
      List<Object> queue_free;

      /// @brief Cria uma instância de processo do jogo
      GameProcess();

      /// @brief Destroy uma instância de processo do jogo
      ~GameProcess();
      
      /// @brief Inicia o loop do jogo
      void execute();

      /// @brief Realiza a atualização do sprite do objeto, entre outras coisas
      /// @param object o objeto
      void animate(Object2D* object);

      /// @brief Reordenada a ordem dos objetos com base no `depth` de cada um
      void sort();

      /// @brief Retorna o frame atual do jogo
      /// @return o frame
      unsigned short int getFrame();

      /// @brief Avança o jogo para o próximo frame
      void nextFrame();

      /// @brief Diz se o jogo ainda está rodando
      /// @return verdadeiro, se estiver, falso caso contrário
      bool isRunning();

      bool checkPaused();

      void setPaused(bool pause);

      void resizeWindow(unsigned int newWidth, unsigned int newHeight);
  };
};