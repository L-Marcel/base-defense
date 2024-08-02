#include <Menus.hpp>

namespace Game {
  wstring ShopMenu::description;

  string ShopMenu::type() {
    return "ShopMenu";
  };

  void ShopMenu::step() {
    bool isHovered = false;
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Button* button = (Button*) this->objects.get(i);
      if(button->isHovered()) {
        isHovered = true;
        break;
      };
    };

    if(!isHovered) ShopMenu::description = L"";
    this->information->setText(ShopMenu::description);
    this->information->setAlignCenter();
  };

  ShopMenu::~ShopMenu() {
    ShopMenu::description = L"";
  };

  ShopMenu::ShopMenu(string spriteSheet, Box box) 
  : Menu(spriteSheet, box) {};

  ShopMenu* ShopMenu::create() {
    ShopMenu* shopMenu = new ShopMenu("shop_screen.png", Box(0, 0, 1280, 720));
    shopMenu->pausable = false;
    shopMenu->position.x = 0;
    shopMenu->position.y = 0;
    shopMenu->depth = 400;
    GameProcess::add(shopMenu);

    // vector<unsigned short int> items = {
    //   HEALTH_UPGRADE,
    //   REGENERATION_UPGRADE,
    //   BASE_UPGRADE,
    //   REPAIR_UPGRADE
    // };

    shopMenu->objects.add(ItemButton::create(HEALTH_UPGRADE));
    shopMenu->objects.add(ItemButton::create(REGENERATION_UPGRADE));
    shopMenu->objects.add(ItemButton::create(BASE_UPGRADE));
    shopMenu->objects.add(ItemButton::create(REPAIR_UPGRADE));

    float x = 160;
    float ww = 1280.0 / 4.0;
    for(unsigned short int i = 0; i < shopMenu->objects.length(); i++) {
      shopMenu->objects.get(i)->position = Point(x, 125);
      x += ww;
    };
    
    ResumeButton* resumeButton = ResumeButton::create();
    resumeButton->position = CENTER;
    resumeButton->position.y += 150;
    shopMenu->objects.add(resumeButton);

    shopMenu->information = Text::create(CENTER, "");
    shopMenu->information->setText(ShopMenu::description);
    shopMenu->information->setAlignCenter();
    shopMenu->information->depth = shopMenu->depth + 10;
    shopMenu->texts.add(shopMenu->information);

    return shopMenu;
  };
};