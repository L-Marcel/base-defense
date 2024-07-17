#include <Engine/objects.hpp>
#include <Engine.hpp>

namespace Game {
    class Text : public Object {
        public:
            void step(GameProcess* gp);
            string type();
            void draw(GameProcess* gp);

            ~Text();
            Text();

            void setTextPosition(float x, float y);
            void setTextFont(sf::Font& font);
            void setText(string content);
            void setTextCharacterSize(unsigned int size);
            void setTextColor(sf::Color color);
            void loadFontFromFile(string fontFile);
        private:
            sf::Text text;
            sf::Font font;
    };
};