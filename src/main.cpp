#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Starter Template", sf::Style::Resize | sf::Style::Close);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("/users/trippyy28/Desktop/RPG/src/Healer.png");

    Player player(&playerTexture, sf::Vector2u(3, 3), 0.3f, 150.0f);
    float deltaTime = 0.0f;
    sf::Clock clock;
    while (window.isOpen())
    {

        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                /* Resize the window */
                break;
            }
        }
        player.Update(deltaTime);
        window.clear();
        player.Draw(window);
        window.display();
    }
}