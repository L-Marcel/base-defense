#include <Misc/item.hpp>

namespace Game {
  Item::Item(
    string name, 
    function<float()> upgrade,
    function<string(Item*)> description,
    function<void(Item*)> action,
    function<unsigned int()> price,
    unsigned short int rarity
  ) {
    this->name = name;
    this->upgrade = upgrade;
    this->description = description;
    this->action = action;
    this->rarity = rarity;
    this->price = price;
  };
};