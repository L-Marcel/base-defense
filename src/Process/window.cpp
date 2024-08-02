#include <Engine.hpp>

namespace Game {
  const Window& GameProcess::getWindow() {
    return GameProcess::gp->window;
  };

  void GameProcess::setResolution(Resolution resolution) {
    GameProcess::gp->window.setSize(Vector<unsigned int>(resolution));
    GameProcess::gp->view.setSize(resolution);
    GameProcess::gp->view.setCenter(resolution.x/2.0, resolution.y/2.0);
  };

  void GameProcess::changeFullscreen() {
    GameProcess* gp = GameProcess::gp;

    if(gp->fullscreen) {
      View view(sf::FloatRect(0, 0, 1280, 720));
      gp->fullscreen = false;
      gp->window.create(
        VideoMode(gp->view.getSize().x, gp->view.getSize().y),
        "Base Defense",
        sf::Style::Close | sf::Style::Titlebar
      );
      gp->window.setView(view);
      gp->window.setFramerateLimit(60);
    } else if(!gp->fullscreen){
      gp->fullscreen = true;
      View view(sf::FloatRect(0, 0, 1280, 720));
      sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
      gp->window.create(desktopMode, "teste", sf::Style::Fullscreen);
      gp->window.setView(view);
      Resolution res(desktopMode.width, desktopMode.height);
      gp->window.setFramerateLimit(60);
    };
  };
};