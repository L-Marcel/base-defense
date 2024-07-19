#include <Tests.hpp>
#include "_mock.cpp"

namespace Mouse {
    Vector<float> position(Window* _) {
        return Vector<float>(1.0, 1.0);
    }
}

TEST(PlayerTest, Type) {
    GameProcess gp;
    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));
    EXPECT_EQ(player->type(), "Player");
}

TEST(PlayerTest, Destroy) {
    GameProcess gp;
    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));
    player->destroy();
    EXPECT_EQ((int) gp.objects.length(), 0);
}