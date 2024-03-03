#include "objects.hpp"

namespace lm {
  class Room : public Instantiable {
    private:
      unsigned int width;
      unsigned int height;
    public:
      List<ObjectType> objects;
      string title;

      Room();
      Room(string title, unsigned int width, unsigned int height);

      void step(GameProcess* gp, RenderWindow* window, unsigned short int frame);
      unsigned int addObject(Object* object);
      void destroyObject(unsigned int id);
      unsigned int getObjectsAmount();
  } typedef RoomType;
};