#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

#define screen_length 350 // X
#define screen_width 600  // Y
#define line_length 300
#define spacing 100
#define h_pos0 200
#define v_pos0 300
#define gravity 350
#define fps 1 / 60
#define speed -350
#define deltaTime 0.1

int main()
{
    {
        Game game;
        // game.Render();
        while (game.isgame())
        {
            game.HandleInput();
            game.Update();

            game.Render();

            game.RestartClock();
        }
    }
}
// {
//     sf::RenderWindow window(sf::VideoMode({screen_length, screen_width}), "Geometry-dash");
//     window.setFramerateLimit(60);

//     sf::Clock clock;
//     sf::Texture texture = sf::Texture::loadFromFile("../textures/yellowbird-midflap.png").value();
//     sf::Sprite bird_mid(texture);
//     bird_mid.setPosition(sf::Vector2f(screen_length / 2, screen_width / 2));
//     bool falling = true;

//     while (window.isOpen())

//     {
//         // Process events
//         while (const auto event = window.pollEvent())
//         {
//             // Close window: exit
//             if (event.is<sf::Event::Closed>())
//             {
//                 printf("window closed");
//                 window.close();
//             }

//             if (event.is<sf::Event::KeyPressed>())
//             {

//                 switch (event.getIf<sf::Event::KeyPressed>()->code)
//                 {
//                 case sf::Keyboard::Key::Space:
//                     falling = false;
//                     clock.restart();
//                     break;

//                 default:
//                     break;
//                 }
//             }
//         }

//         // Clear screen
//         window.clear();
//         // process bird movement
//         if (!falling)
//         {
//             bird_mid.move(sf::Vector2f(0, speed * fps));
//         }
//         else
//         {
//             bird_mid.move(sf::Vector2f(0, gravity * fps));
//         }
//         if (clock.getElapsedTime().asSeconds() > 0.25)
//         {
//             falling = true;
//         }

//         window.draw(bird_mid);

//         window.display();
//     }

//     return 0;
