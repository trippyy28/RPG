#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, std::string buttonText);
    void draw(sf::RenderWindow &window);
    bool isClicked(sf::RenderWindow &window);
};