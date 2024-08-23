#include "World.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

World::World(std::shared_ptr<GameData> _data) : bird(_data->window.getSize()), windowSize(_data->window.getSize()), data(_data)
{
    // bird = Bird(size);

    spawnPipes();
}

void World::reset()
{
    spawnPipes();
    bird.resetPosition(windowSize);
}

/// sf::Vector2i position(4, 2);
/// sf::Vector2i size(18, 10);
/// sf::IntRect r2(position, size);

void World::spawnPipes()
{
    int startPos = 600;
    int interLeave = 100;

    std::srand(std::time(0));
    for (int i = 0; i < 50; i += 2)
    {
        int randomNumber = 50 + std::rand() % 151;

        int gap = 100 + std::rand() % 131;

        sf::Vector2i positionD(0, 0);
        sf::Vector2i sizeD(52, randomNumber);

        sf::Vector2i positionU(0, 0);
        sf::Vector2i sizeU(52, 512 - randomNumber - gap);

        pipes[i] = sf::IntRect(positionD, sizeD);
        posOfPipes[i] = sf::Vector2f(startPos + i * interLeave + 52, randomNumber);

        pipes[i + 1] = sf::IntRect(positionU, sizeU);
        posOfPipes[i + 1] = sf::Vector2f(startPos + i * interLeave, 512 - sizeU.y);
    }
}

void World::movePipes(float dt)
{
    for (int i = 0; i < 50; i++)
    {
        posOfPipes[i].x -= 100 * dt;
    }
}
void World::drawPipes(sf::RenderWindow &window)
{
    pipeDown.setScale({-1.0f, -1.0f});
    for (int i = 0; i < 50; i += 2)
    {
        pipeDown.setTextureRect(pipes[i]);
        pipeDown.setPosition(posOfPipes[i]);
        pipeBound[i] = pipeDown.getGlobalBounds();

        // pipeDown.setRotation(sf::Angle(3 / 2));

        window.draw(pipeDown);

        pipeUp.setTextureRect(pipes[i + 1]);
        pipeUp.setPosition(posOfPipes[i + 1]);
        pipeBound[i + 1] = pipeUp.getGlobalBounds();
        window.draw(pipeUp);

        // handle UpPipe
    }
    // pipeDown.setScale({1.0f, 1.0f});
}
void World::handleInput(sf::Event &event)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        switch (event.getIf<sf::Event::KeyPressed>()->code)
        {
        case sf::Keyboard::Key::Space:
            // std::cout << "pressedd space" << std::endl;
            bird.handleInput(event);
            break;
        case sf::Keyboard::Key::Escape:
            data->states.popState();
            break;

        default:
            break;
        }
    }
}

void World::update(float dt)
{
    // std::cout << "world update" << std::endl;
    movePipes(dt);
    bird.moveUp(dt);
}

void World::draw()
{
    // std::cout << "world drwa" << std::endl;
    data->window.clear();
    data->window.draw(background);
    drawPipes(data->window);

    bird.draw(data->window);

    if (checkCollisons())
    {
        data->states.pushState(state(new GameOver(data)));
    }
    data->window.display();
}

void World::pause()
{
}

void World::resume()
{
}

bool World::checkCollisons()
{
    sf::Rect<float> bird_bound = bird.getBounds();

    if (bird.getPosition().y <= 0 || bird.getPosition().y > windowSize.y)
        return true;

    bool collison = false;
    for (int i = 0; i < 50; i++)
    {
        if (bird_bound.findIntersection(pipeBound[i]))
        {
            collison = true;
            break;
        }
    }

    return collison;
}