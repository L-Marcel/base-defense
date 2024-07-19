#include <iostream>
#include <Game.hpp>

using namespace Game;

int main() {
    GameProcess gp;
    
    Music music("default.ogg");
    music.setVolume(30);
    music.play();

//     Player player("assets/player.png", Box(12, 14, 24, 28));
//     player.scale(4);
//     player.animate(8, 1, false);
//     player.x = gp.getWindowWidth()/2;
//     player.y = gp.getWindowHeight()/2;
//     player.CircCollision(32);
    
//     Example example("assets/ball.png", Box(8, 8, 16, 16));
//     example.scale(4);
//     example.x = 400;
//     example.y = 300;
//     example.CircCollision(36);

//     Collision col;
//     col.collision_between(player.type(), example.type());
//     cout << col.getType1() << endl;
//     cout << col.getType2() << endl;

//     gp.addObject(&player);
//     gp.addObject(&example);
//     gp.addCol(&col);

    Text::create(&gp, Vector<float>(300.f, 250.f), "Exemplo");
    Player* player = Player::create(&gp, "player.png", Box(12, 14, 24, 28));
    player->scale(4);
    player->animate(8, 1, false);
    
    gp.execute();

    return EXIT_SUCCESS;
}