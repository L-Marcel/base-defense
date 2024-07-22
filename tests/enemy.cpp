#include <Tests.hpp>

TEST(EnemyTest, Type) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Object2D* base = Object2D::create(&gp, "ball.png", Box(8, 8, 16, 16));
  Enemy* enemy = Enemy::create(&gp, player, base);
  EXPECT_EQ(enemy->type(), "Enemy");
}

TEST(EnemyTest, Destroy) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Object2D* base = Object2D::create(&gp, "ball.png", Box(8, 8, 16, 16));
  Enemy* enemy = Enemy::create(&gp, player, base);
  enemy->free();
  EXPECT_EQ((int) gp.objects.length(), 2);
}