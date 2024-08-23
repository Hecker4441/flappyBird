#pragma once
#include <SFML/Graphics.hpp>
#include "bird.hpp"
#include "State.hpp"
#include <memory>
#include "game.hpp"
#include "gameOver.hpp"

class World : public State
{
private:
    Bird bird;

    std::shared_ptr<GameData> data;

    sf::Vector2u windowSize;
    // sf::RenderWindow &window;
    sf::Vector2f posOfPipes[50];

    sf::IntRect pipes[50];

    sf::Rect<float> pipeBound[50];

    sf::Texture textureUp = sf::Texture::loadFromFile("../textures/pipe.png").value();

    sf::Texture textureDown = sf::Texture::loadFromFile("../textures/pipedown.png").value();
    sf::Sprite pipeDown = sf::Sprite(textureUp);

    sf::Sprite pipeUp = sf::Sprite(textureUp);

    sf::Texture back = sf::Texture::loadFromFile("../textures/background-day.png").value();
    sf::Sprite background = sf::Sprite(back);

public:
    // World();
    World(std::shared_ptr<GameData>);
    void load(sf::Vector2u);
    void reset();

    void spawnPipes();
    void movePipes(float dt);
    void drawPipes(sf::RenderWindow &window);

    bool checkCollisons();

    void handleInput(sf::Event &);

    void update(float dt);
    void draw();

    void pause();
    void resume();
};