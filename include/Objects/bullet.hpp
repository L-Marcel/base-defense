#include <Objects.hpp>

namespace Game {
  class Bullet : public Object2D {
    public:
      virtual string type();
      void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      virtual ~Bullet();

      /// @brief Cria uma instância de um projétil
      /// @param gp ponteiro do processo do jogo
      /// @param object o objeto que a disparou
      /// @param ally se o projétil é aliado ao jogador ou não
      static Bullet* create(GameProcess* gp, Object2D* object, bool ally = false);

      /// @brief Diz se a bala é aliada ao jogador ou não
      /// @return `true` se for aliada, `false` caso contrário
      bool isAlly();
      bool canBeBlocked = true;
    protected:
      using Object2D::Object2D;
      bool ally = false;
  };
};