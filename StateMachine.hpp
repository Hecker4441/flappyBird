#pragma once

#include "State.hpp"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> state;

class StateMachine
{
private:
    std::stack<state> states;

public:
    // state getActiveState();
    StateMachine();
    void pushState(state newState, bool isReplacing = true);

    void popState();

    // pop the top state and push the newState
    // void replaceState(state newState);

    state &getActiveState();
};