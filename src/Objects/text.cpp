#include <Objects/text.hpp>

namespace Game {
  string Text::type() {
    return "Text";
  };
  
  void Text::draw() {
    this->gp->window.draw(this->text);
  };

  Text::~Text() {};
  
  Text::Text() {
    this->loadFontFromFile("assets/fonts/PixeloidMono.ttf");
    this->setTextFont(this->font);
  };

  Text* Text::create(GameProcess* gp, Vector<float> position, string content) {
    Text* instance = new Text();
    instance->setTextPosition(position);
    instance->setText(content);
    instance->gp = gp;
    gp->objects.add(instance);
    return instance;
  };

  void Text::setTextPosition(Vector<float> position) {
    this->text.setPosition(position);
  };

  void Text::setTextFont(sf::Font& font) {
    this->text.setFont(font);
  };

  void Text::setText(string content) {
    this->text.setString(content);
  };

  void Text::setTextCharacterSize(unsigned int size) {
    this->text.setCharacterSize(size);
  };

  void Text::setTextColor(sf::Color color) {
    this->text.setFillColor(color);
  };

  void Text::loadFontFromFile(string filename) {
    this->font.loadFromFile(filename);
  };
};