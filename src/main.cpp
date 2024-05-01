#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileMap.h" // Ensure the header file name matches
#include "Button.h"
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Starter Template", sf::Style::Resize | sf::Style::Close);

    sf::Texture tileSet;
    sf::Music music;

    if (!music.openFromFile("/users/trippyy28/Desktop/RPG/src/loop.wav"))
    {
        std::cerr << "Failed to load music!" << std::endl;
    }

    music.play();
    music.setLoop(true);

    // Initialize your map (assuming you have tile data and dimensions)
    int level[4096] = {
        // Your map's tile indices, e.g., 0, 1, 2, 3, etc.
        // Array size should be 'width * height'
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,

    };
    unsigned int width = 64;  // Width of your map in tiles
    unsigned int height = 64; // Height of your map in tiles

    TileMap map;
    if (!map.load("/users/trippyy28/Desktop/RPG/src/Tileset-export.png", sf::Vector2u(16, 16), level, width, height))
    {
        std::cerr << "Failed to load map tiles!" << std::endl;
    }

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("/users/trippyy28/Desktop/RPG/src/Healer.png"))
    {
        std::cerr << "Failed to load player texture!" << std::endl;
    }
    Player player(&playerTexture, sf::Vector2u(3, 3), 0.3f, 150.0f);
    Button button(50, 50, 50, 50, "Toggle Music");

    sf::Clock clock;
    float deltaTime = 0.0f;
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
            case sf::Event::MouseButtonPressed:
                if (button.isClicked(window))
                {
                    std::cout << "Button clicked!" << std::endl;
                    if (music.getStatus() == sf::Music::Playing)
                        music.pause();
                    else
                        music.play();
                }
                break;
            }
        }

        player.Update(deltaTime);

        window.clear();
        window.draw(map); // Draw the map before the player to ensure it's in the background
        button.draw(window);
        player.Draw(window);
        window.display();
    }
}
