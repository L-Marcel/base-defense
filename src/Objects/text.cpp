#include <Objects/text.hpp>

namespace Game {
  string Text::type() {
    return "Text";
  };
  
  void Text::draw() {
    GameProcess::draw(this->text);
  };

  Text::~Text() {};
  
  Text::Text() {
    this->loadFontFromFile("assets/fonts/pixeloid_mono.ttf");
    this->setFont(this->font);
  };

  Text* Text::create(Point position, string content) {
    Text* text = new Text();
    text->setPosition(position);
    text->setText(content);
    GameProcess::add(text);
    return text;
  };

  void Text::setPosition(Point position) {
    this->text.setPosition(position);
  };

  void Text::setFont(sf::Font& font) {
    this->text.setFont(font);
  };

  void Text::setText(string content) {
    this->text.setString(content);
  };

  void Text::setSize(unsigned int size) {
    this->text.setCharacterSize(size);
  };

  void Text::setColor(sf::Color color) {
    this->text.setFillColor(color);
  };

  void Text::loadFontFromFile(string filename) {
    this->font.loadFromFile(filename);
  };
};