#include <Character.hpp>
#include <Engine/playerfinder.hpp>
#include <Objects/base.hpp>
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
      static Enemy* create(GameProcess* gp, Player* player, Base* base);

      /// @brief Realiza um disparo
      void shoot();

      Sound shoot_sound = Sound("shoot.mp3");
      bool focusingBase = true;
      Player* player = nullptr;
      Playerfinder path;
    protected:
      using Character::Character;
      double range = 200.0;
      
      Wall* wab = nullptr;
      Wall* wbc = nullptr;
      Wall* wcd = nullptr;
      Wall* wda = nullptr;
  };
};