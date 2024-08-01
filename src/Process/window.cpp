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
      gp->fullscreen = false;
      gp->window.create(
        VideoMode(gp->view.getSize().x, gp->view.getSize().y),
        "Base Defense",
        sf::Style::Close | sf::Style::Titlebar
      );
      gp->window.setFramerateLimit(60);
    } else if(VideoMode::getFullscreenModes().size() > 0) {
      for(unsigned int i = 0; i < VideoMode::getFullscreenModes().size(); i++) {
        VideoMode mode = VideoMode::getFullscreenModes().at(i);
        if(mode.isValid()) {
          gp->fullscreen = true;
          gp->window.create(
            mode,
            "Base Defense",
            sf::Style::Fullscreen
          );
          gp->window.setFramerateLimit(60);
          gp->window.setSize(Vector<unsigned int>(gp->view.getSize()));
          break;
        };
      };
    };
  };
};