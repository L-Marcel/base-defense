#include <Menus.hpp>
#include <Misc/shop.hpp>

namespace Game {
  string ShopMenu::description;

  string ShopMenu::type() {
    return "ShopMenu";
  };

  void ShopMenu::step() {
    bool is_hovered = false;
    for(unsigned int i = 0; i < this->objects.length(); i++) {
      Button* button = (Button*) this->objects.get(i);
      if(button->isHovered()) {
        is_hovered = true;
        break;
      };
    };

    if(!is_hovered) ShopMenu::description = "";
    this->information->setText(ShopMenu::description);
    this->information->setAlignCenter();
  };

  ShopMenu::~ShopMenu() {
    ShopMenu::description = "";
  };

  ShopMenu::ShopMenu(string sprite_sheet, Box box) 
  : Menu(sprite_sheet, box) {};

  ShopMenu* ShopMenu::create() {
    ShopMenu* shop_menu = new ShopMenu("shop_screen.png", Box(0, 0, 1280, 720));
    shop_menu->pausable = false;
    shop_menu->position.x = 0;
    shop_menu->position.y = 0;
    shop_menu->depth = 400;
    GameProcess::add(shop_menu);

    Shop::reset();
    ItemButton::create(shop_menu);
    ItemButton::create(shop_menu, COMMON);

    if(rand() % 100 >= 60) ItemButton::create(shop_menu, RARE);
    else ItemButton::create(shop_menu, COMMON);

    if(rand() % 100 >= 80) ItemButton::create(shop_menu, EPIC);
    else if(rand() % 100 >= 60) ItemButton::create(shop_menu, RARE);
    else ItemButton::create(shop_menu, COMMON);

    float x = 160;
    float ww = 320;
    for(unsigned short int i = 0; i < shop_menu->objects.length(); i++) {
      shop_menu->objects.get(i)->position = Point(x, 125);
      x += ww;
    };

    x = 160;
    ww = 320;
    for(unsigned short int i = 0; i < shop_menu->texts.length(); i++) {
      Text* text = shop_menu->texts.get(i);
      text->setPosition(Point(x, 200));
      text->setAlignCenter();
      x += ww;
    };
    
    ResumeButton* resume_button = ResumeButton::create();
    resume_button->position = CENTER;
    resume_button->position.y += 200;
    shop_menu->objects.add(resume_button);

    shop_menu->information = Text::create(CENTER, "");
    shop_menu->information->setText(ShopMenu::description);
    shop_menu->information->setAlignCenter();
    shop_menu->information->depth = shop_menu->depth + 10;
    shop_menu->texts.add(shop_menu->information);

    return shop_menu;
  };
};