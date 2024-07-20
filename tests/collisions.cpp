#include<Tests.hpp>

TEST(CollisionTest, Destroy) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Collision* collision = Collision::create(&gp, player, "Example");
  EXPECT_EQ((int) player->collisions.length(), 1);
  collision->free();
  EXPECT_EQ((int) player->collisions.length(), 0);
};

TEST(CollisionTest, Step) {
  GameProcess gp;
  Player* player = Player::create(&gp);
  Collision* collision = Collision::create(&gp, player, "Object2D");
  Object2D* object = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  object->setCircle(1);
  object->position = player->position;
  collision->step();
  EXPECT_EQ((int) player->collisions.length(), 1);
  EXPECT_EQ((int) player->colliders.length(), 1);
  EXPECT_EQ(player->colliders.get(0), object);
  object->free();
  collision->step();
  EXPECT_EQ((int) player->colliders.length(), 0);
  collision->free();
  EXPECT_EQ((int) player->collisions.length(), 0);
};

TEST(CollisionTest, Circles) {
  GameProcess gp;

  Object2D* first = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  first->setCircle(1);

  Object2D* second = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  second->setCircle(1);
  second->position = first->position;
  
  EXPECT_TRUE(Collision::hasCirclesCollision(first, first));
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::hasRectanglesCollision(first, first));
  EXPECT_TRUE(Collision::hasCirclesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCirclesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCirclesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCirclesCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCirclesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::hasCirclesCollision(first, second));
};

TEST(CollisionTest, Rectangles) {
  GameProcess gp;

  Object2D* first = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  first->setRectangle(1, 1);

  Object2D* second = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::hasCirclesCollision(first, first));
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, first));
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, first));
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, first));
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.99, 90);
  second->collision();
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 90);
  second->collision();
  EXPECT_FALSE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(0.1, 270);
  second->position += Math::pointInRadius(0.99, 180);
  second->collision();
  EXPECT_TRUE(Collision::hasRectanglesCollision(first, second));
};

TEST(CollisionTest, CirclesAndRectangles) {
  GameProcess gp;

  Object2D* first = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  first->setCircle(1);

  Object2D* second = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::hasCirclesCollision(first, second));
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(first, second));
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(second, first));
  EXPECT_FALSE(Collision::hasRectanglesCollision(first, second));
  second->position += Math::pointInRadius(1.0, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.50, 90);
  second->collision();
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.01, 90);
  second->collision();
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(1.01, 270);
  second->collision();
  EXPECT_TRUE(Collision::hasCircleAndRectangleCollision(first, second));
  second->position += Math::pointInRadius(0.01, 270);
  second->collision();
  EXPECT_FALSE(Collision::hasCircleAndRectangleCollision(first, second));
};