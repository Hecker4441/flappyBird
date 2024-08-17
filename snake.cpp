#include "snake.hpp"
#include <iostream>

Snake::Snake(int l_blockSize) : m_size(l_blockSize)
{
    m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset(); // to move the snake back to its starting position
}

Snake::~Snake()
{
}

// This chunk of code will be called every time a new game begins.
void Snake::Reset()
{
    m_snakeBody.clear(); // container for snake body
    // m_snakeBody.push_back(snakeSegment(5, 7));
    // m_snakeBody.push_back(snakeSegment(5, 6));
    // m_snakeBody.push_back(snakeSegment(5, 5));
    m_snakeBody.push_back(snakeSegment(5, 4));
    m_snakeBody.push_back(snakeSegment(5, 3));
    m_snakeBody.push_back(snakeSegment(5, 2));
    m_snakeBody.push_back(snakeSegment(5, 1));

    SetDirection(Direction::None);
    m_speed = 15;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::SetDirection(Direction l_dir) { m_dir = l_dir; }

Direction Snake::GetDirection() { return m_dir; }

sf::Vector2i Snake::GetPosition()
{
    return (!m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1, 1));
}

int Snake::GetLives() { return m_lives; }
int Snake::GetScore() { return m_score; }

void Snake::IncreaseScore() { m_score += 10; }
bool Snake::HasLost() { return m_lost; }
void Snake::Lose() { m_lost = true; }
void Snake::ToggleLost() { m_lost = !m_lost; }
int Snake::GetSpeed() { return m_speed; }

void Snake::Extend()
{
    if (m_snakeBody.empty())
        return;
    snakeSegment &tail_head = m_snakeBody[m_snakeBody.size() - 1];

    if (m_snakeBody.size() > 1)
    {
        snakeSegment &tail_bone =
            m_snakeBody[m_snakeBody.size() - 2];
        if (tail_head.position.x == tail_bone.position.x)
        {
            if (tail_head.position.y > tail_bone.position.y)
            {
                m_snakeBody.push_back(snakeSegment(tail_head.position.x, tail_head.position.y + 1));
            }
            else
            {
                m_snakeBody.push_back(snakeSegment(tail_head.position.x, tail_head.position.y - 1));
            }
        }
        else if (tail_head.position.y == tail_bone.position.y)
        {
            if (tail_head.position.x > tail_bone.position.x)
            {
                m_snakeBody.push_back(snakeSegment(tail_head.position.x + 1, tail_head.position.y));
            }
            else
            {
                m_snakeBody.push_back(snakeSegment(tail_head.position.x - 1, tail_head.position.y));
            }
        }
    }
    else
    {
        if (m_dir == Direction::Up)
        {
            m_snakeBody.push_back(snakeSegment(tail_head.position.x, tail_head.position.y + 1));
        }
        else if (m_dir == Direction::Down)
        {
            m_snakeBody.push_back(snakeSegment(tail_head.position.x, tail_head.position.y - 1));
        }
        else if (m_dir == Direction::Left)
        {
            m_snakeBody.push_back(snakeSegment(tail_head.position.x + 1, tail_head.position.y));
        }
        else if (m_dir == Direction::Right)
        {
            m_snakeBody.push_back(snakeSegment(tail_head.position.x - 1, tail_head.position.y));
        }
    }
}

void Snake::Tick()
{
    if (m_snakeBody.empty())
    {
        return;
    }
    if (m_dir == Direction::None)
    {
        return;
    }
    if (HasLost())
    {
        Reset();
    }
    Move();
    CheckCollision();
}

void Snake::Move()
{
    for (size_t i = m_snakeBody.size() - 1; i > 0; --i)
    {
        m_snakeBody[i].position = m_snakeBody[i - 1].position;
    }
    if (m_dir == Direction::Left)
    {
        --m_snakeBody[0].position.x;
    }
    else if (m_dir == Direction::Right)
    {
        ++m_snakeBody[0].position.x;
    }
    else if (m_dir == Direction::Up)
    {
        --m_snakeBody[0].position.y;
    }
    else if (m_dir == Direction::Down)
    {
        ++m_snakeBody[0].position.y;
    }
}

void Snake::CheckCollision()
{
    if (m_snakeBody.size() < 5)
    {
        return;
    }
    snakeSegment &head = m_snakeBody.front();

    for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
    {
        if (itr->position == head.position)
        {
            size_t segments = m_snakeBody.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake::Cut(size_t l_segments)
{
    for (int i = 0; i < l_segments; ++i)
    {
        m_snakeBody.pop_back();
    }
    --m_lives;
    if (!m_lives)
    {
        Lose();
        return;
    }
}

void Snake::Render(sf::RenderWindow &l_window)
{
    // std::cout << "snake render";
    if (m_snakeBody.empty())
    {
        return;
    }
    auto head = m_snakeBody.begin();
    m_bodyRect.setFillColor(sf::Color::Yellow);
    auto pos = m_bodyRect.getPosition();
    pos.x = head->position.x * m_size;
    pos.y = head->position.y * m_size;
    m_bodyRect.setPosition(pos);
    l_window.draw(m_bodyRect);
    m_bodyRect.setFillColor(sf::Color::Green);
    for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
    {
        auto pos_t = m_bodyRect.getPosition();
        pos_t.x = itr->position.x * m_size;
        pos_t.y = itr->position.y * m_size;
        m_bodyRect.setPosition(pos_t);
        l_window.draw(m_bodyRect);
    }
}