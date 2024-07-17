#pragma once
#include <Engine/base.hpp>

namespace Game {
    class TextureNotFound : public exception {
        public:
            TextureNotFound(string filename);
            ~TextureNotFound();
            virtual const char* what() const throw ();
            const string message;
    };

    class SoundNotFound : public exception {
        public:
            SoundNotFound(string filename);
            ~SoundNotFound();
            virtual const char* what() const throw ();
            const string message;
    };

    class MusicNotFound : public exception {
        public:
            MusicNotFound(string filename);
            ~MusicNotFound();
            virtual const char* what() const throw ();
            const string message;
    };
}