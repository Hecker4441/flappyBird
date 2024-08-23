#include "gameOver.hpp"

GameOver::GameOver(std::shared_ptr<GameData> _data) : data(_data)
{
    spritePos.x = (data->window.getSize().x - sprite.getTextureRect().size.x) / 2;
    spritePos.y = (data->window.getSize().y - sprite.getTextureRect().size.y) / 2;

    sprite.setPosition(spritePos);
}

// handle input

void GameOver::handleInput(sf::Event &event)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        switch (event.getIf<sf::Event::KeyPressed>()->code)
        {
        case sf::Keyboard::Key::Space:
            // move to World
            data->states.pushState(state(new World(data)));
            break;

        case sf::Keyboard::Key::Escape:
            // move to main Menu
            data->states.popState();

            break;

        default:
            break;
        }
    }
}

void GameOver::draw()
{
    data->window.clear();
    data->window.draw(background);
    data->window.draw(sprite);
    data->window.display();
}

void GameOver::update(float dt)
{
}

void GameOver::pause()
{
}

void GameOver::resume()
{
}