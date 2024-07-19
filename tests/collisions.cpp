#include<Tests.hpp>

TEST(CollisionTest, Destroy) {
    GameProcess gp;
    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));
    Collision* collision = Collision::create(&gp, player, "Example");
    EXPECT_EQ((int) player->collisions.length(), 1);
    collision->destroy();
    EXPECT_EQ((int) player->collisions.length(), 0);
};

TEST(CollisionTest, Circles) {
    GameProcess gp;

    Object2D* first = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
    first->setCircle(1);

    Object2D* second = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
    second->setCircle(1);
    second->position = first->position;
    
    EXPECT_TRUE(Collision::CCcollision(first, first));
    EXPECT_FALSE(Collision::CRcollision(first, first));
    EXPECT_FALSE(Collision::CRcollision(first, first));
    EXPECT_FALSE(Collision::RRcollision(first, first));
    EXPECT_TRUE(Collision::CCcollision(first, second));
    second->position += Math::pointInRadius(0.5, 0);
    second->collision();
    EXPECT_TRUE(Collision::CCcollision(first, second));
    second->position += Math::pointInRadius(0.5, 0);
    second->collision();
    EXPECT_TRUE(Collision::CCcollision(first, second));
    second->position += Math::pointInRadius(0.5, 0);
    second->collision();
    EXPECT_TRUE(Collision::CCcollision(first, second));
    second->position += Math::pointInRadius(0.49, 0);
    second->collision();
    EXPECT_TRUE(Collision::CCcollision(first, second));
    second->position += Math::pointInRadius(0.1, 0);
    second->collision();
    EXPECT_FALSE(Collision::CCcollision(first, second));
};

TEST(CollisionTest, Rectangles) {
    GameProcess gp;

    Object2D* first = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
    first->setRectangle(1, 1);

    Object2D* second = Object2D::create(&gp, "player.png", Box(12, 14, 24, 28));
    second->setRectangle(1, 1);
    second->position = first->position;

    EXPECT_FALSE(Collision::CCcollision(first, first));
    EXPECT_FALSE(Collision::CRcollision(first, first));
    EXPECT_FALSE(Collision::CRcollision(first, first));
    EXPECT_TRUE(Collision::RRcollision(first, first));
    EXPECT_TRUE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.5, 0);
    second->collision();
    EXPECT_TRUE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.49, 0);
    second->collision();
    EXPECT_TRUE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.1, 0);
    second->collision();
    EXPECT_FALSE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.1, 180);
    second->position += Math::pointInRadius(0.99, 90);
    second->collision();
    EXPECT_TRUE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.1, 90);
    second->collision();
    EXPECT_FALSE(Collision::RRcollision(first, second));
    second->position += Math::pointInRadius(0.1, 270);
    second->position += Math::pointInRadius(0.99, 180);
    second->collision();
    EXPECT_TRUE(Collision::RRcollision(first, second));
};