#pragma once

#include <SFML/Graphics.hpp>

class Bird
{
private:
    sf::Texture texture = sf::Texture::loadFromFile("../textures/yellowbird-midflap.png").value();
    sf::Sprite sprite = sf::Sprite(texture);
    sf::Vector2f position;

    float gravity = 200;
    float velocity = 0;

    enum state
    {
        falling,
        flying
    };

    state bird_state = state::falling;

public:
    // Bird();
    Bird(sf::Vector2u screenSize);
    void moveUp(float);
    void moveDown();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f);
    void resetPosition(sf::Vector2u);

    void draw(sf::RenderWindow &window);
    void changeState();
    void handleInput(sf::Event &event);
    sf::Rect<float> getBounds();
};