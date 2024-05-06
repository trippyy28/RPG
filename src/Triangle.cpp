#include "Triangle.h"

Triangle::Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color)
{
    triangle.setPrimitiveType(sf::Triangles);
    triangle.resize(3);

    triangle[0].position = p1;
    triangle[1].position = p2;
    triangle[2].position = p3;

    for (int i = 0; i < 3; ++i)
    {
        triangle[i].color = color;
    }
}

void Triangle::draw(sf::RenderWindow &window)
{
    window.draw(triangle);
}
