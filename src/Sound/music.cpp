#include <Sound.hpp>

namespace Game {
  Music::Music(string filename) {
    if(filename.empty()) throw new MusicNotFound(filename);
    if(!this->openFromFile("assets/musics/" + filename)) {
      throw new MusicNotFound(filename);
    };
    setLoop(true);
  };
}