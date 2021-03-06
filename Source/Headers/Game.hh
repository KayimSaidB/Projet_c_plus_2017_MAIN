#ifndef __GAME_HH
#define __GAME_HH
#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hh"
#include "Joueur.hh"
#include "CarteSpeciale.hh"
#define WIDTH 1200
#define HEIGHT 720

class Game
{
public:
    Game();
    void run();
    ~Game(){};

private:
    void processEvents(Joueur* joueur1,Joueur * joueur2,Terrain *unbeauterrain,CarteSpeciale spetypebien,CarteSpeciale spesecondtypebien);
    void update(Joueur* joueur1,Joueur * joueur2,Terrain *unbeauterrain,CarteSpeciale spetypebien,CarteSpeciale spesecondtypebien);
    void render(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain,CarteSpeciale spetypebien,CarteSpeciale spesecondtypebien);
    void afficher_terrain_vide(Joueur *joueur1,Joueur *joueur2);
    void afficher_carte_main(Joueur *joueur1,Joueur *joueur2);
    sf::RenderWindow window;
    void afficher_terrain_rempli(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain);
    void main_phase(Joueur* joueur1);
    void choix_attaquant(Joueur *joueur1,Terrain *unbeauterrain);
    void choix_attaque(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain);
    void afficher_Victoire(int indice);
    void afficher_cara_joueur(Joueur *joueur1,Joueur *joueur2);
};

#endif