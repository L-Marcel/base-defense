#include <Sound.hpp>

namespace Game {
    Sound::~Sound() {
        delete this->getBuffer();
    };
    Sound::Sound(string filename) {
        sf::SoundBuffer* buffer = new sf::SoundBuffer();
        
        if(filename.empty()) throw new SoundNotFound(filename);
        if(buffer->loadFromFile("assets/sounds/" + filename)){
            setBuffer(*buffer);
        } else {
            throw new SoundNotFound(filename);
        };
    };
}