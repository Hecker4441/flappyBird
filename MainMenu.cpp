#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(std::shared_ptr<GameData> _data) : data(_data)
{

    // set the initial position of the sprite
    // std::cout << "mainMenu constructor1" << std::endl;

    sf::Vector2u size = data->window.getSize();
    spritePosMenu.x = (size.x - menu.getTextureRect().size.x) / 2;
    spritePosMenu.y = (size.y - menu.getTextureRect().size.y) / 2;

    menu.setPosition(spritePosMenu);
}

MainMenu::~MainMenu()
{
    std::cout << "MainMenu DECONSTRUCTOR_1" << std::endl;
}

void MainMenu::handleInput(sf::Event &event)
{
    // std::cout << "handleInput_1" << std::endl;
    // while (auto event = data->window.pollEvent())
    // {
    //     std::cout << "handleInput_2" << std::endl;
    //     if (std::cout << "const" && event.is<sf::Event::Closed>()) // culprit
    //     {
    //         std::cout << "handleInput_3" << std::endl;
    //         data->window.close();
    //     }
    //     if (std::cout << "const1" && event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space)
    //     {
    //         // got to world state
    //     }
    //     std::cout << "handleInput_4" << std::endl;
    // }

    // std::cout << "handleInput_5" << std::endl;

    // if (event.is<sf::Event::Closed>())
    //     data->window.close();

    // std::cout << "faulty" << std::endl;
    if (event.is<sf::Event::KeyPressed>())
    {
        switch (event.getIf<sf::Event::KeyPressed>()->code)
        {
        case sf::Keyboard::Key::Space:
            data->window.clear();
            data->states.pushState(state(new World(data)), false);
            break;

        default:
            break;
        }
    }
}

void MainMenu::draw()
{
    // std::cout << "mainMenu draw 1" << std::endl;
    data->window.clear();

    data->window.draw(background);
    data->window.draw(menu);
    data->window.display();
    // std::cout << "mainMenu draw 2" << std::endl;
}

void MainMenu::update(float dt)
{
}

void MainMenu::init()
{
}

void MainMenu::pause()
{
}

void MainMenu::resume()
{
}
