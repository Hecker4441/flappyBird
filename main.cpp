#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "game.hpp"

void move(sf::RectangleShape &, float);

int direction = 1;

int main()
{
    std::cout << "main" << std::endl;
    sf::Vector2u size(288, 512);

    Game game(size);
    std::cout << "run" << std::endl;
    game.run();

    // Game game(size);
    // game.data->states.getActiveState();
    // game.data->states.getActiveState();

    // float dt = 1 / 60.0;

    // sf::RenderWindow window(sf::VideoMode({288, 512}), "Flappy Bird");

    // window.setFramerateLimit(60);
    // World world(window.getSize());
    // // world.load(window.getSize());
    // sf::Texture back = sf::Texture::loadFromFile("../textures/background-day.png").value();
    // sf::Sprite background = sf::Sprite(back);

    // // sf::Texture pipe_texture = sf::Texture::loadFromFile("../textures/pipe.png").value();

    // // sf::Sprite pipe = sf::Sprite(pipe_texture);
    // // sf::Angle an = sf::degrees(90);

    // // pipe.setTextureRect({{0, 0}, {52, 200}});

    // // pipe.setRotation(an);

    // sf::RectangleShape rect({50, 50});
    // rect.setPosition({0, 200});
    // rect.setFillColor(sf::Color::Red);

    // sf::Clock clock;

    // float currentTime = clock.restart().asSeconds();

    // while (window.isOpen())
    // {

    //     while (auto event = window.pollEvent())
    //     {
    //         if (event.is<sf::Event::Closed>())
    //         {
    //             window.close();
    //         }
    //         if (event.is<sf::Event::KeyPressed>())
    //         {
    //             // switch (event.getIf<sf::Event::KeyPressed>()->code)
    //             // {
    //             // case sf::Keyboard::Key::Space:

    //             //     break;

    //             // default:
    //             //     break;
    //             // }
    //             world.HandleInput(event);
    //         }
    //     }

    //     window.clear();
    //     window.draw(background);

    //     // window.draw(pipe);

    //     float newTime = clock.getElapsedTime().asSeconds();
    //     float deltatime = newTime - currentTime;

    //     currentTime = newTime;

    //     world.update(deltatime);
    //     world.draw(window);

    //     // move(rect, deltatime);

    //     // bird.moveUp(deltatime);
    //     // bird.draw(window);
    //     // window.draw(rect);
    //     window.display();
    // }
}

void move(sf::RectangleShape &rect, float dt)
{
    sf::Vector2f pos = rect.getPosition();
    if (pos.x < 0 || pos.x > 610)
    {
        direction *= -1;
    }
    pos.x += 200 * direction * dt;

    rect.setPosition(pos);
}
