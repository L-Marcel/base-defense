#include <Tests.hpp>

TEST(EnemyTest, Type) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Base* base = Base::create(&gp);
  Enemy* enemy = Enemy::create(&gp, player, base);
  EXPECT_EQ(enemy->type(), "Enemy");
}