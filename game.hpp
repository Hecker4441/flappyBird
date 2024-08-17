#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "snake.hpp"
#include "world.hpp"
#include "Window.hpp"

class Game
{
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    //            Window* GetWindow();
    float GetElapsed();
    void RestartClock();
    bool isgame();

private:
    sf::RenderWindow window;
    World m_world;
    Snake m_snake;
    sf::Clock m_clock;
    float m_elapsed;
};