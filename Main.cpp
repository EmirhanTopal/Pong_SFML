#include <iostream>
#include "Header/Core/GameWindowManager.h"
#include "Header/Core/Event.h"
#include "Header/Core/GameLoop.h"

using namespace Core_N;
using namespace Event_N;

int main()
{
    // Create our window manager instance
    GameWindowManager _gameWindowManager;
    EventManager _eventManager;
    GameLoop _gameLoop;

    _gameLoop.initialize();
    while (_gameLoop.isGameRunning())
    {
        _gameLoop.poolEvent(_gameWindowManager.getGameWindow());
        _gameLoop.render();
        _gameLoop.render();
    }
    return 0;
}