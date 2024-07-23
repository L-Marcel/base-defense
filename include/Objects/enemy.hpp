#include <Character.hpp>
#include <Objects/player.hpp>
#include <Objects/bullet.hpp>
#include <Sound.hpp>

namespace Game {
  class Enemy : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      using Character::draw;
      using Character::free;
      virtual ~Enemy();

      /// @brief Cria uma instância do Enemy
      /// @param gp ponteiro do processo do jogo 
      /// @param player ponteiro para o player
      /// @param base ponteiro para a base
      static Enemy* create(GameProcess* gp, Player* player, Object2D* base);

      /// @brief Realiza um disparo
      void shoot();

      Sound shoot_sound = Sound("shoot.mp3");
    protected:
      using Character::Character;
      Player* targetPlayer;
      Object2D* base;
      double range = 200.000; // Valor ilustrativo, ainda a ser definido
  };
};