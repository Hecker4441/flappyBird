#pragma once

#include "State.hpp"
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "World.hpp"

class MainMenu : public State
{
private:
    sf::Vector2f spritePosMenu;
    std::shared_ptr<GameData> data;

    sf::Texture back = sf::Texture::loadFromFile("../textures/background-day.png").value();
    sf::Texture ture = sf::Texture::loadFromFile("../textures/message.png").value();
    sf::Sprite menu = sf::Sprite(ture);
    sf::Sprite background = sf::Sprite(back);

public:
    void handleInput(sf::Event &event);
    void draw();
    void init();

    void pause();
    void resume();

    void update(float dt);
    MainMenu(std::shared_ptr<GameData>);

    ~MainMenu();
};
