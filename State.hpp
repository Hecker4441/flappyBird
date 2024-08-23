#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
class State
{
public:
    virtual void handleInput(sf::Event &) = 0;
    virtual void update(float) = 0;
    virtual void draw() = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;

    // virtual void init() = 0;

    virtual ~State() = default;
};