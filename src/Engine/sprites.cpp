#include <Engine/sprites.hpp>
#include <Engine/errors.hpp>

namespace Game {
  map<string, Texture*> Sprites::loaded = {};

  Sprite* Sprites::load(string filename, Box box) {
    Texture* texture;
    Sprite* sprite = new Sprite();
    map<string, Texture*>::iterator it = Sprites::loaded.find(filename);

    if(Sprites::loaded.end() != it) {
      texture = it->second;
    } else {
      texture = new Texture();
      if(!texture->loadFromFile(filename)) {
        delete sprite;
        delete texture;
        throw new TextureNotFound(filename);
      };
    };

    sprite->setTexture(*texture);
    Vector<int> pos = box.getPosition();
    box.top = 0;
    box.left = 0;
    sprite->setTextureRect(box);
    sprite->setOrigin(pos.x, pos.y);
    sprite->setScale(1, 1);

    Sprites::loaded.insert(pair<string, Texture*>(
      filename,
      texture
    ));

    return sprite;
  };

  void Sprites::clear() {
    for(map<string, Texture*>::iterator it = Sprites::loaded.begin(); it != Sprites::loaded.end(); ++it) {
      delete it->second;
    };
  };
};