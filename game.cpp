#include "game.hpp"


Game::Game() : window(sf::VideoMode({800, 600}), "Snake"),
               m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
     window.setFramerateLimit(30);

}
Game::~Game()
{
}

float Game::GetElapsed() { return m_elapsed; }

void Game::RestartClock() { m_elapsed = m_clock.restart().asSeconds(); }

void Game::Update()
{
    float timestep = 1.0f / m_snake.GetSpeed();
    if (m_elapsed >= timestep)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= timestep;
        if (m_snake.HasLost())
        {
            m_snake.Reset();
        }
    }
}
void Game::HandleInput()
{

    
    while (const auto event = window.pollEvent())
    {
        if (event.is<sf::Event::Closed>() || (event.is<sf::Event::KeyPressed>() && event.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
            {
                window.close();
                break;
            }
        if (event.is<sf::Event::KeyPressed>())
            {

                switch (event.getIf<sf::Event::KeyPressed>()->code)
                {
                    case sf::Keyboard::Key::Up:
                        m_snake.SetDirection(Direction::Up);
                        break;
                    case sf::Keyboard::Key::Down:
                        m_snake.SetDirection(Direction::Down);
                        break;

                    case sf::Keyboard::Key::Left:
                         m_snake.SetDirection(Direction::Left);
                         break;


                    case sf::Keyboard::Key::Right:
                         m_snake.SetDirection(Direction::Right);
                         break;

                default:
                    break;
                }
            }
        // if (event.type == sf::Event::Closed)
        // {
        //     window.close();
        // }
        // if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down)
        // {
            
        // }
        // else if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up)
        // {
        //     m_snake.SetDirection(Direction::Down);
        // }
        // else if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right)
        // {
        //     m_snake.SetDirection(Direction::Left);
        // }
        // else if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left)
        // {
        //     m_snake.SetDirection(Direction::Right);
        // }
    }
}

bool Game::isgame()
{
    return window.isOpen();
}

void Game::Render()
{

    window.clear();
    // Render here.
    
    m_snake.Tick();
    m_snake.Render(window);
    m_world.Update(m_snake);
    m_world.Render(window);
    window.display();
}
