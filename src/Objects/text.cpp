#include <Objects/text.hpp>

namespace Game {
    void Text::step(GameProcess* gp) {};

    string Text::type(){
        return "Text";
    };

    void Text::draw(GameProcess* gp) {
        gp->window.draw(this->text);
    };
    
    Text::~Text() {};

    Text::Text() {
        this->loadFontFromFile("assets/fonts/PixeloidMono.ttf");
        this->setTextFont(this->font);
    };

    void Text::setTextPosition(float x,float y) {
        this->text.setPosition(x,y);
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

    void Text::loadFontFromFile(string fontFile) {
        this->font.loadFromFile(fontFile);
    };
};