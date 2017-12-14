#ifndef __TERRAIN_HH
#define __TERRAIN_HH

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
class Terrain{
protected:
std::vector<Carte*> _carte_joueur1;
std::vector<Carte*> _carte_joueur2;
int nbretour;
int tempstour;

public:
	int get_nbrtour();
	int get_tempstour();
	void push_that_card( Carte* macarte, int numerojoueur);


};

#endif
