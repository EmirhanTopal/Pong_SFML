#include <iostream>
#include "Header/Core/GameWindowManager.h"
#include "Header/Core/Event.h"

int main()
{
    // Create our window manager instance
    Core_N::GameWindowManager _gameWindowManager;
    Event_N::EventManager _eventManager;

    _gameWindowManager.initialize();
    while (_gameWindowManager.isGameRunning())
    {
        _eventManager.PoolEvents(_gameWindowManager.getGameWindow());
        _gameWindowManager.render();
    }
    return 0;
}