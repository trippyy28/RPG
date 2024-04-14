#include "Player.h"
#include <iostream>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;

    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
}
Player::~Player()
{
}
void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    bool hasMoved = false; // Flag to check if the player has moved

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed * deltaTime;
        if (row != 3)
        { // Check if the row needs to be updated
            row = 3;
        }
        hasMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed * deltaTime;
        if (row != 1)
        { // Check if the row needs to be updated
            row = 1;
        }
        hasMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= speed * deltaTime;
        if (row != 0)
        { // Check if the row needs to be updated
            row = 0;
        }
        hasMoved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed * deltaTime;
        if (row != 2)
        { // Check if the row needs to be updated
            row = 2;
        }
        hasMoved = true;
    }

    // Update the animation only if the player has moved
    if (hasMoved)
    {
        animation.update(row, deltaTime);
    }

    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}
