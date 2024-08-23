#include "StateMachine.hpp"
#include <iostream>

// state StateMachine::getActiveState()
// {
//     return states.top();
// }

StateMachine::StateMachine()
{
    std::cout << "stateMachine constructor" << std::endl;
}

void StateMachine::pushState(state newState, bool isReplacing)
{
    std::cout << "statemachine push state" << std::endl;
    if (isReplacing)
    {
        if (!states.empty())
            states.pop();

        std::cout << "pushed state" << std::endl;

        states.push(std::move(newState));
    }
    else
    {

        states.push(std::move(newState));
    }
}

void StateMachine::popState()
{

    states.pop();
}

state &StateMachine::getActiveState()
{

    if (!states.empty())
    {
        // std::cout << "Get active state" << std::endl;
        return states.top();
    }
}