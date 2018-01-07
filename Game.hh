#ifndef __GAME_HH
#define __GAME_HH
#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hh"
#include "Joueur.hh"

#define WIDTH 800
#define HEIGHT 600

class Game
{
public:
    Game();
    void run();

private:
    void processEvents(Joueur* joueur1,Joueur * joueur2,Terrain *unbeauterrain);
    void update(Joueur* joueur1,Joueur * joueur2,Terrain *unbeauterrain);
    void render(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain);

    sf::RenderWindow window;
};

#endif