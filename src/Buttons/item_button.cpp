#include <Buttons.hpp>
#include <Menus/shop_menu.hpp>
#include <Objects/player.hpp>
#include <Objects/base.hpp>

namespace Game {
  string ItemButton::type() {
    return "ItemButton";
  };

  void ItemButton::step() {
    if(this->isHovered()) {
      this->animate(1, 1, 1, false);
      ShopMenu::description = this->description;

      if(Mouse::isLeftReleased()) {
        this->action();
        GameProcess::resume();
      };
    } else this->animate(1, 1, 0, false);
  };

  ItemButton::~ItemButton() {};

  ItemButton* ItemButton::create(unsigned short int item) {
    string texture = "health_upgrade.png";
    wstring description = L"Aumenta a vida em +10 pontos";
    function<void()> action = [](){
      Player::get()->health.upgrade(10);
    };

    switch(item) {
      case BASE_UPGRADE:
        texture = "base_upgrade.png";
        description = L"Aumenta a vida da base em +10 pontos";
        action = [](){
          Base::get()->health.upgrade(10);
        };
        break;
      case REPAIR_UPGRADE:
        texture = "repair_upgrade.png";
        description = L"O reparo da base fica 20% mais rápido";
        action = [](){
          Base::get()->regeneration *= 1.2;
        };
        break;
      case REGENERATION_UPGRADE:
        texture = "regeneration_upgrade.png";
        description = L"Aumenta a recuperação de vida em 20%";
        action = [](){
          Player::get()->regeneration *= 1.2;
        };
      default:
        break;
    };

    ItemButton* itemButton = new ItemButton(texture, Box(28, 28, 56, 56));
    itemButton->animate(1, 1, 0, false);
    itemButton->pausable = false;
    itemButton->action = action;
    itemButton->depth = 500;
    itemButton->position = CENTER;
    itemButton->description = description;
    itemButton->scale(3);

    GameProcess::add(itemButton);
    return itemButton;
  };
};