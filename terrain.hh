#ifndef __TERRAIN_HH
#define __TERRAIN_HH

#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
class Terrain{
protected:
std::vector<Carte*> carte_joueur;
int nbretour;
int tempstour;

public:
	int get_nbrtour();
	int get_tempstour();



};

#endif
