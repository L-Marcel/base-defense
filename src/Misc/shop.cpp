#include <Misc/shop.hpp>
#include <Objects.hpp>

namespace Game {
  string Shop::showcase[3] = {"", "", ""};

  map<string, unsigned short int> Shop::common_stock = {
    {"base", 7},
    {"health", 6},
    {"max_clip", 4},
    {"max_ammo", 6},
    {"attack_speed", 4}
  };

  map<string, unsigned short int> Shop::rare_stock = {
    {"repair_speed", 9},
    {"regeneration", 7},
    {"sentry_speed", 4}
  };

  map<string, unsigned short int> Shop::epic_stock = {
    {"ricochet", 1},
    {"friendly_fire", 1},
    {"ammo_consume", 1}
  };

  bool Shop::purchase(Item* item) {
    if(item->price() > GameProcess::money) {
      return false;
    };

    map<string, unsigned short int>* items = nullptr;
    switch(item->rarity) {
      case COMMON:
        items = &Shop::common_stock;
        break;
      case RARE:
        items = &Shop::rare_stock;
        break;
      case EPIC:
        items = &Shop::epic_stock;
        break;
      default:
        break;
    };

    if(items != nullptr) {
      map<string, unsigned short int>::iterator it = items->find(item->name);
      if(it != items->end() && it->second > 0) {
        GameProcess::money -= item->price();
        item->action(item);
        it->second--;
        return true;
      } else {
        return false;
      };
    };

    GameProcess::money -= item->price();
    item->action(item);

    return true;
  };

  void Shop::reset() {
    Shop::showcase[0] = "";
    Shop::showcase[1] = "";
    Shop::showcase[2] = "";
  };

  vector<string> Shop::get_available_offers(unsigned short int rarity) {
    map<string, unsigned short int> items;
    vector<string> available_options = {};

    switch(rarity) {
      case COMMON:
        items = Shop::common_stock;
        break;
      case RARE:
        items = Shop::rare_stock;
        break;
      case EPIC:
        items = Shop::epic_stock;
        break;
      default:
        return available_options;
    };
    
    vector<string> options = {};

    for(map<string, unsigned short int>::iterator it = items.begin(); it != items.end(); ++it) {
      options.push_back(it->first);
    };

    for(unsigned int i = 0; i < options.size(); i++) {
      string option = options.at(i);
      bool already_in_showcase = false;
      for(unsigned int j = 0; j < Shop::showcase->length(); j++) {
        if(Shop::showcase[j] == option) already_in_showcase = true;
      };

      if(!already_in_showcase && items.at(option) > 0) available_options.push_back(option);
    };

    return available_options;
  };

  Item* Shop::get_offer(unsigned short int rarity) {
    if(rarity == GUARANTEED) {
      string options[3] = {"heal", "repair", "ammo"};
      return &Shop::items.at(options[rand() % 3]);
    } else {
      vector<string> available_options = Shop::get_available_offers(rarity);

      unsigned short int trys = 2;
      while(available_options.size() == 0 && trys > 0) {
        rarity = (Rarity) (1 + (rarity % 3));
        available_options = Shop::get_available_offers(rarity);
        trys--;
      };

      if(trys <= 0) return Shop::get_offer(GUARANTEED);
      
      vector<string>::iterator it = available_options.begin() + (rand() % available_options.size());
      Item* item = &Shop::items.at(*it);

      for(unsigned int i = 0; i < 3; i++) {
        if(Shop::showcase[i].empty()) {
          Shop::showcase[i] = item->name;
          break;
        };
      };

      return item;
    };
  };
};