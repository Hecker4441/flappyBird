#include "bird.hpp"
#include <iostream>

// Bird::Bird() {}

Bird::Bird(sf::Vector2u size)
{
    position.x = size.x / 2;
    position.y = size.y / 2;

    sprite.setPosition(position);
}

void Bird::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

sf::Rect<float> Bird::getBounds()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Bird::getPosition()
{
    return sf::Vector2f(position.x, position.y);
}

void Bird::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

// handle movement of the bird

void Bird::handleInput(sf::Event &event)
{
    if (event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space)
    {
        bird_state = flying;
    }
}

void Bird::changeState()
{
    bird_state = Bird::state::flying;
    // std::cout << "change state" << std::endl;
}

void Bird::moveUp(float dt)
{

    if (bird_state == Bird::state::flying)
    {
        velocity = -200;
        position.y -= 10;
        bird_state = Bird::state::falling;
    }
    position.y += velocity * dt;
    velocity += gravity * dt;

    sprite.setPosition(position);
}

void Bird::resetPosition(sf::Vector2u size)
{
    position.x = size.x / 2;
    position.y = size.y / 2;

    sprite.setPosition(position);
}