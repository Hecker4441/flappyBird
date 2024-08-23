#pragma once

#include "State.hpp"
#include "game.hpp"
#include "World.hpp"

class GameOver : public State
{

private:
    sf::Texture over = sf::Texture::loadFromFile("../textures/gameover.png").value();
    sf::Sprite sprite = sf::Sprite(over);

    sf::Texture back = sf::Texture::loadFromFile("../textures/background-day.png").value();
    sf::Sprite background = sf::Sprite(back);
    std::shared_ptr<GameData> data;
    sf::Vector2f spritePos;

public:
    void handleInput(sf::Event &);
    void draw();
    void update(float);
    void pause();
    void resume();

    GameOver(std::shared_ptr<GameData>);
};