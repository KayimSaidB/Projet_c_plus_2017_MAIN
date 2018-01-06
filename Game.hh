#ifndef __GAME_HH
#define __GAME_HH
#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hh"

#define WIDTH 800
#define HEIGHT 600

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
};

#endif