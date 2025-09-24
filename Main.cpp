#include <iostream>
#include "Header/Core/GameWindowManager.h" 

int main()
{
    // Create our window manager instance
    Core::GameWindowManager _gameWindowManager;

    _gameWindowManager.initialize();
    while (_gameWindowManager.isGameRunning())
    {
        _gameWindowManager.render();
    }
    return 0;
}