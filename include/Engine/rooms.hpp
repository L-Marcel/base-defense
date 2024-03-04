#include "objects.hpp"

namespace lm {
  class Room : public Instantiable {
    private:
      unsigned int width;
      unsigned int height;
    public:
      List<Object> objects;
      string title;

      Room();
      Room(string title, unsigned int width, unsigned int height);

      void step(GameProcess* gp, Window* window, unsigned short int frame);
      unsigned int addObject(Object* object);
      void destroyObject(unsigned int id);
      unsigned int getObjectsAmount();
  } typedef Room;
};