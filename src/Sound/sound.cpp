#include <Sound.hpp>

namespace Game {
  Sound::~Sound() {
    delete this->getBuffer();
  };

  Sound::Sound(string filename) {
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    
    if(filename.empty()) {
      delete buffer;
      throw new SoundNotFound(filename);
    };

    if(buffer->loadFromFile("assets/sounds/" + filename)){
      setBuffer(*buffer);
    } else {
      delete buffer;
      throw new SoundNotFound(filename);
    };
  };
}