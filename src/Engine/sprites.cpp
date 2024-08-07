#include <Engine/sprites.hpp>
#include <Engine/errors.hpp>

namespace Game {
  map<string, Sprite*> Sprites::loaded = {};

  Sprite* Sprites::load(string filename, Box box) {
    map<string, Sprite*>::iterator it = Sprites::loaded.find(filename);

    if(Sprites::loaded.end() != it) return it->second;

    Texture* texture = new Texture();
    if(texture->loadFromFile(filename)) {
      Sprite* sprite = new Sprite();
      sprite->setTexture(*texture);
      Vector<int> pos = box.getPosition();
      box.top = 0;
      box.left = 0;
      sprite->setTextureRect(box);
      sprite->setOrigin(pos.x, pos.y);
      sprite->setScale(1, 1);
      Sprites::loaded.insert(pair<string, Sprite*>(
        filename,
        sprite
      ));
      return sprite;
    };

    delete texture;
    throw new TextureNotFound(filename);
  };

  void Sprites::clear() {
    for(map<string, Sprite*>::iterator it = Sprites::loaded.begin(); it != Sprites::loaded.end(); ++it) {
      delete it->second->getTexture();
      delete it->second;
    };
  };
};