#include "game.hpp"
#include "MainMenu.hpp"
#include <iostream>

Game::Game(sf::Vector2u size)
{
    // std::cout << "GAME CONSTRUCTOR1" << std::endl;
    data->window.create(sf::VideoMode(size), "flappy bird");
    // std::cout << "GAME CONSTRUCTOR2" << std::endl;

    // std::cout << "GAME CONSTRUCTOR3" << std::endl;

    // run();
}

void Game::run()
{
    sf::Clock clock;
    data->states.pushState(state(new MainMenu(data)));

    float currentTime = clock.restart().asSeconds();
    while (data->window.isOpen())
    {

        while (auto event = data->window.pollEvent())
        {
            if (event.is<sf::Event::Closed>())
                data->window.close();
            // std::cout << "game loop 1" << std::endl;
            data->states.getActiveState()->handleInput(event);
        }

        float newTime = clock.getElapsedTime().asSeconds();
        float deltaTime = newTime - currentTime;
        currentTime = newTime;

        data->states.getActiveState()->update(deltaTime);

        data->states.getActiveState()->draw();

        // std::cout << "GAME Loop end" << std::endl;
    }
}