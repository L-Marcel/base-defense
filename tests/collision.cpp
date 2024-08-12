#include <Tests.hpp>

TEST(CollisionTest, Destroy) {
  Player* player = Player::create();
  Collision* collision = Collision::create(player, "Example");
  int amount = (int) player->collisions.length();
  collision->destroy();
  EXPECT_EQ((int) player->collisions.length(), amount - 1);
};

TEST(CollisionTest, Step) {
  Player* player = Player::create();
  Collision* collision = Collision::create(player, "Object2D");
  Object2D* object = Object2D::create("player.png", Box(12, 14, 24, 28));
  object->position = player->position;
  object->setCircle(1);
  collision->step();
};

TEST(CollisionTest, Circles) {
  Object2D* first = Object2D::create("player.png", Box(12, 14, 24, 28));
  first->setCircle(1);

  Object2D* second = Object2D::create("player.png", Box(12, 14, 24, 28));
  second->position = first->position;
  second->setCircle(1);
  
  EXPECT_TRUE(Collision::has_circlesCollision(first, first));
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::has_rectanglesCollision(first, first));
  EXPECT_TRUE(Collision::has_circlesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circlesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circlesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circlesCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circlesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_circlesCollision(first, second));
};

TEST(CollisionTest, Rectangles) {
  Object2D* first = Object2D::create("player.png", Box(12, 14, 24, 28));
  first->setRectangle(1, 1);

  Object2D* second = Object2D::create("player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::has_circlesCollision(first, first));
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, first));
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, first));
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.99, 90);
  second->collision();
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 90);
  second->collision();
  EXPECT_FALSE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 270);
  second->position += Math::pointInRadius(0.99, 180);
  second->collision();
  EXPECT_TRUE(Collision::has_rectanglesCollision(first, second));
};

TEST(CollisionTest, CirclesAndRectangles) {
  Object2D* first = Object2D::create("player.png", Box(12, 14, 24, 28));
  first->setCircle(1);

  Object2D* second = Object2D::create("player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::has_circlesCollision(first, second));
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(first, second));
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(second, first));
  EXPECT_FALSE(Collision::has_rectanglesCollision(first, second));
  second->position += Math::pointInRadius(1.0, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.50, 90);
  second->collision();
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.01, 90);
  second->collision();
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(1.01, 270);
  second->collision();
  EXPECT_TRUE(Collision::has_circleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.01, 270);
  second->collision();
  EXPECT_FALSE(Collision::has_circleAndRectangleCollision(first, second));
};