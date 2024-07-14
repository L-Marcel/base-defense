#include <Tests.hpp>
#include "_mock.cpp"

namespace Mouse {
    Vector<float> position(Window* _) {
        return Vector<float>(1.0, 1.0);
    }
}

TEST(PlayerTest, Type) {
    Player player("assets/player.png", Box(12, 14, 24, 28));
    EXPECT_EQ(player.type(), "Player");
}

TEST(PlayerTest, Destroy) {
    GameProcess gp;
    Player* player = new Player("assets/player.png", Box(12, 14, 24, 28));
    gp.addObject(player);
    player->destroy();
    EXPECT_EQ(gp.objects.length(), 0);
    //EXPECT_EQ(player, nullptr);
}