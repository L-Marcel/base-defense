#include <Objects/medicalkit.hpp>

namespace Game {

  string MedicalKit::type() {
    return "MedicalKit";
  };

  void MedicalKit::step() {};

  MedicalKit::~MedicalKit() {};

  void MedicalKit::drop() {
    bool isDropAllowed = (rand() % 100) < 25;
    if(isDropAllowed) {
      this->gp->objects.add(this);
    }
  };

  MedicalKit* MedicalKit::create(GameProcess* gp, Vector<float> enemyPosition) {
    MedicalKit* medkit = new MedicalKit("ball.png", Box(8, 8, 16, 16)); // Mudar sprite depois
    medkit->setCircle(10);
    medkit->scale(2);
    medkit->depth = 50;
    medkit->gp = gp;
    medkit->position.y = enemyPosition.y + 20.f; // Provavelmente será revisto quando incluirmos os kit de munição
    medkit->position.x = enemyPosition.x;
    return medkit;
  };
};