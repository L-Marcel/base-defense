#include <Tests.hpp>

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
  
  EXPECT_TRUE(Collision::has_circles_collision(first, first));
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, first));
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, first));
  EXPECT_FALSE(Collision::has_rectangles_collision(first, first));
  EXPECT_TRUE(Collision::has_circles_collision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circles_collision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circles_collision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circles_collision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circles_collision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_circles_collision(first, second));
};

TEST(CollisionTest, Rectangles) {
  Object2D* first = Object2D::create("player.png", Box(12, 14, 24, 28));
  first->setRectangle(1, 1);

  Object2D* second = Object2D::create("player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::has_circles_collision(first, first));
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, first));
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, first));
  EXPECT_TRUE(Collision::has_rectangles_collision(first, first));
  EXPECT_TRUE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.5, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.99, 90);
  second->collision();
  EXPECT_TRUE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.1, 90);
  second->collision();
  EXPECT_FALSE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(0.1, 270);
  second->position += Math::pointInRadius(0.99, 180);
  second->collision();
  EXPECT_TRUE(Collision::has_rectangles_collision(first, second));
};

TEST(CollisionTest, CirclesAndRectangles) {
  Object2D* first = Object2D::create("player.png", Box(12, 14, 24, 28));
  first->setCircle(1);

  Object2D* second = Object2D::create("player.png", Box(12, 14, 24, 28));
  second->setRectangle(1, 1);
  second->position = first->position;

  EXPECT_FALSE(Collision::has_circles_collision(first, second));
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(first, second));
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(second, first));
  EXPECT_FALSE(Collision::has_rectangles_collision(first, second));
  second->position += Math::pointInRadius(1.0, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(0.49, 0);
  second->collision();
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(0.1, 0);
  second->collision();
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(0.1, 180);
  second->position += Math::pointInRadius(0.50, 90);
  second->collision();
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(0.01, 90);
  second->collision();
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(1.01, 270);
  second->collision();
  EXPECT_TRUE(Collision::has_circle_and_rectangle_collision(first, second));
  second->position += Math::pointInRadius(0.01, 270);
  second->collision();
  EXPECT_FALSE(Collision::has_circle_and_rectangle_collision(first, second));
};