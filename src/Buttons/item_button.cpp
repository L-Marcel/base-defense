#include <Buttons.hpp>
#include <Menus/shop_menu.hpp>
#include <Objects/player.hpp>
#include <Objects/base.hpp>
#include <Misc/shop.hpp>

namespace Game {
  string ItemButton::type() {
    return "ItemButton";
  };

  void ItemButton::step() {
    if(this->isHovered()) {
      this->animate(1, 1, 1, false);
      ShopMenu::description = this->item->description(this->item);

      if(Mouse::isLeftReleased()) {
        if(Shop::purchase(this->item) && this->item->rarity > 0) {
          this->destroy();
          for(unsigned int i = 0; i < this->menu->objects.length(); i++) {
            Object2D* object = this->menu->objects.get(i);
            if(object == this) {
              this->menu->objects.remove(i);
              break;
            };
          };
        };
      };
    } else this->animate(1, 1, 0, false);
  };

  ItemButton::~ItemButton() {};

  ItemButton* ItemButton::create(ShopMenu* menu, unsigned short int rarity) {
    Item* item = Shop::get_offer(rarity);
    ItemButton* itemButton = new ItemButton(item->name + "_upgrade.png", Box(28, 28, 56, 56));
    itemButton->menu = menu;
    itemButton->item = item;
    itemButton->animate(1, 1, 0, false);
    itemButton->pausable = false;
    itemButton->depth = 500;
    itemButton->position = CENTER;
    itemButton->scale(3);

    GameProcess::add(itemButton);
    return itemButton;
  };
};