#pragma once

#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"

struct GameData
{
    sf::RenderWindow window;
    StateMachine states;
};

class Game
{
private:
    bool isPlaying;

public:
    Game(sf::Vector2u);
    std::shared_ptr<GameData> data = std::make_shared<GameData>();

    void run();
};