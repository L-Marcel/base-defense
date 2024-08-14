#include <Objects/medical_kit.hpp>

namespace Game {
  const float MedicalKit::heal = 10.0;

  string MedicalKit::type() {
    return "MedicalKit";
  };

  void MedicalKit::step() {
    this->timer.tick();
    if(this->timer.isFinished()) this->destroy();
  };

  MedicalKit::~MedicalKit() {};

  MedicalKit* MedicalKit::create(Point position) {
    MedicalKit* med_kit = new MedicalKit("med_kit.png", Box(6, 5, 12, 10));
    med_kit->setCircle(10);
    med_kit->scale(2);
    med_kit->depth = 50;
    med_kit->position = position;
    med_kit->position.y += 20.0;
    med_kit->timer.start(10);
    return med_kit;
  };
};