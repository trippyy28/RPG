#include "Button.h"

Button::Button(float x, float y, float width, float height, std::string buttonText)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    font.loadFromFile("/users/trippyy28/Desktop/RPG/src/font.ttf"); // replace with the path to your font file
    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(
        shape.getPosition().x + (shape.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2),
        shape.getPosition().y + (shape.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2));
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            return true;
        }
    }
    return false;
}