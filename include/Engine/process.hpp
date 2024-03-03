#include "rooms.hpp"

namespace lm {
  class GameProcess {
      private:
        unsigned short int width = 800;
        unsigned short int height = 600;
        string title = "L-Marcel's Game Engine";
        RenderWindow window = RenderWindow(VideoMode(800, 600), "L-Marcel's Game Engine");
        unsigned short int frame = 0;
        Clock clock;
        unsigned int room = 0;
        bool redraw = false;
        void (*events)(Event::EventType);

      public:
        List<RoomType> rooms;
        bool running = true;

        GameProcess();
        GameProcess(
          unsigned short int width, 
          unsigned short int height,
          string title
        );

        unsigned int addRoom(Room* room);
        void step();
        unsigned short int getFrame();
        void nextFrame();
        bool isRunning();
        void on(void (*func)(Event::EventType));
  };
};