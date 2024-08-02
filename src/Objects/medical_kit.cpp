#include <Objects/medical_kit.hpp>

namespace Game {
  string MedicalKit::type() {
    return "MedicalKit";
  };

  void MedicalKit::step() {
    this->timer.start();
    if(this->timer.isFinished()) this->destroy();
  };

  MedicalKit::~MedicalKit() {};

  MedicalKit* MedicalKit::create(Point position) {
    MedicalKit* medkit = new MedicalKit("medkit.png", Box(5, 6, 12, 10));
    medkit->setCircle(10);
    medkit->scale(2);
    medkit->depth = 50;
    medkit->position = position;
    medkit->position.y += 20.0;
    medkit->timer.setDuration(10);
    return medkit;
  };
};