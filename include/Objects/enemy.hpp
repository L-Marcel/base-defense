#include <Character.hpp>
#include <Engine/playerfinder.hpp>
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
      static Enemy* create(GameProcess* gp, Player* player);

      /// @brief Realiza um disparo
      void shoot();

      Sound shoot_sound = Sound("shoot.mp3");
      Player* player = nullptr;
      Playerfinder path;
    protected:
      using Character::Character;
      double range = 200.0;
  };
};