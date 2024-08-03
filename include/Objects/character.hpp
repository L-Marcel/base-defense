#pragma once
#include <Objects.hpp>

namespace Game {
  class Character : public Object2D {
    public:
      virtual string type();
      using Object2D::step;
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Character();

      /// @brief Cria uma instância de um personagem
      /// @param spriteSheet página de textura do sprite de um personagem
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      static Character* create(string spriteSheet, Box box);

      mutable Health health;
      mutable Ammo clip;
      mutable float damage = 10;
      mutable float attack_speed = 1;
      mutable float regeneration = 0;
      mutable float not_consume_ammo_chance = 0;
    protected:
      /// @brief Cria uma instância de um personagem
      /// @param spriteSheet página de textura do sprite do personagem
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      /// @param base_ammo a quantidade inicial de munição, também considerada o limite
      /// @param base_health o quantidade inicial de vida, também considerada o limite
      Character(string spriteSheet, Box box, unsigned int base_ammo = 12, float base_health = 100);
      Character();
  };
};