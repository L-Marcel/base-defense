#include <Engine.hpp>
#include <stdexcept>

namespace Game {
    TextureNotFound::TextureNotFound(string filename) : message("Não foi possível carregar a textura '" + filename + "'!") {};
    TextureNotFound::~TextureNotFound() {};
    const char* TextureNotFound::what() const throw () {
        return message.c_str();
    };

    SoundNotFound::SoundNotFound(string filename) : message("Não foi possível carregar o som '" + filename + "'!") {};
    SoundNotFound::~SoundNotFound() {};
    const char* SoundNotFound::what() const throw () {
        return message.c_str();
    };

    MusicNotFound::MusicNotFound(string filename) : message("Não foi possível carregar a música '" + filename + "'!") {};
    MusicNotFound::~MusicNotFound() {};
    const char* MusicNotFound::what() const throw () {
        return message.c_str();
    };
};