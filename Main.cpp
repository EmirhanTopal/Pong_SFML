#include <iostream>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/Event.h"
#include "Header/Core/GameLoop.h"


using namespace Core_N;
using namespace Event_N;

int main()
{
    // Create our window manager instance
    GameLoop _gameLoop;

    _gameLoop.initialize();
    while (_gameLoop.isGameRunning())
    {
        _gameLoop.poolEvent();
        _gameLoop.update();
        _gameLoop.render();
    }
    return 0;
}