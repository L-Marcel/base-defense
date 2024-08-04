#include <Objects/text.hpp>
#include <Engine/process.hpp>

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

  Text* Text::create(Point position, string content, int size) {
    Text* text = new Text();
    text->setPosition(position);
    text->setText(content);
    text->setSize(size);

    GameProcess::add(text);

    return text;
  };

  void Text::setAlignCenter() {
    FloatRect textBounds = this->text.getLocalBounds();
    this->text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
  };

  void Text::setPosition(Point position) {
    this->text.setPosition(position);
  };

  void Text::setFont(sf::Font& font) {
    this->text.setFont(font);
  };

  void Text::setText(string content) {
    wstring_convert<codecvt_utf8_utf16<wchar_t>> conveter;
    this->text.setString(conveter.from_bytes(content));
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