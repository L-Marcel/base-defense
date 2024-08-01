#include <Objects/medical_kit.hpp>

namespace Game {
  string MedicalKit::type() {
    return "MedicalKit";
  };

  MedicalKit::~MedicalKit() {};

  void MedicalKit::drop() {
    if((rand() % 100) < 25) GameProcess::add(this);
  };

  MedicalKit* MedicalKit::create(Point position) {
    MedicalKit* medkit = new MedicalKit("ball.png", Box(8, 8, 16, 16));
    medkit->setCircle(10);
    medkit->scale(2);
    medkit->depth = 50;
    position.y += 20.0;
    medkit->position = position;
    return medkit;
  };
};