#ifndef __TERRAIN_HH
#define __TERRAIN_HH

#include <iostream>
#include <string>
#include <vector>
#include "CarteMonstre.h"
#include <map>
class Terrain{
protected:
std::vector<CarteMonstre> _carte_joueur1;
std::vector<CarteMonstre> _carte_joueur2;
int _nbtour;
int _temps;
std::map<int,bool> already_attack1;
std::map<int,bool> already_attack2;

public:
	Terrain(int nbtour, int temps);
	std::vector<CarteMonstre> get_carte_joueur1(int indice);
	bool already_attack_fun(int indicejoueur,int indicecarte);
	std::vector<CarteMonstre> get_carte_joueur2();
	bool attack_enclenche(int attaquant, int attaque,int numerojoueur);
	int get_nbrtour();
	int get_tempstour();
	void push_that_card( CarteMonstre macarte, int numerojoueur);
	void attack_reinit(int indice);
	void set_already_attack(int indicejoueur,int indicecarte){if (indicejoueur==1) already_attack1[indicecarte]=true;
	else already_attack2[indicecarte]=false; }

	void afficher_terrain ();
	~Terrain(){};

};

#endif
