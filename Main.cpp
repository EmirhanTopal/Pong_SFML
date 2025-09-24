#include <iostream>
#include "Header/Core/Event.h"
#include "Header/Core/GameWindowManager.h"

int main()
{
    // Create our window manager instance
    Core_N::GameWindowManager _gameWindowManager;
    Event_N::EventManager _eventManager;

    _gameWindowManager.initialize();
    while (_gameWindowManager.isGameRunning())
    {
        _gameWindowManager.render();
        _eventManager.PoolEvents(_gameWindowManager.getGameWindow());
    }
    return 0;
}