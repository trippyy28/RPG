#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>

class Triangle
{
private:
    sf::VertexArray triangle;

public:
    Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color);
    void draw(sf::RenderWindow &window);
};

#endif // TRIANGLE_H