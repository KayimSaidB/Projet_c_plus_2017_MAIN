#ifndef __TERRAIN_HH
#define __TERRAIN_HH

#include <iostream>
#include <string>
#include <vector>
#include "CarteMonstre.h"
class Terrain{
protected:
std::vector<CarteMonstre> _carte_joueur1;
std::vector<CarteMonstre> _carte_joueur2;
int _nbtour;
int _temps;

public:
	Terrain(int nbtour, int temps);
	std::vector<CarteMonstre> get_carte_joueur1();
	std::vector<CarteMonstre> get_carte_joueur2();
	
	void attack_enclenche(int attaquant, int attaque,int numerojoueur);
	int get_nbrtour();
	int get_tempstour();
	void push_that_card( CarteMonstre macarte, int numerojoueur);

	void afficher_terrain ();
};

#endif
