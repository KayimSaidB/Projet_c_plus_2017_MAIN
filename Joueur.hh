#ifndef __JOUEUR_HH
#define __JOUEUR_HH
#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
#include "Terrain.hh"
class Joueur {

protected:
int _pts_action ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
int _pointdevie;
std::string _nom;
std::vector<Carte*> _carte_main;
std::vector<Carte*> _carte_deck;

public:
	int get_point_action();
	int get_Nb_carte_main();
	int get_Nb_carte_deck();
	int get_pointdevie(); 
	std::string get_nom();
	void pioche_une_carte();
	void pose_une_carte(Terrain terrainactuel);
	void declarer_une_attaque(std::string macarte,std::string carteadverse,Terrain actuel);
	Carte choisir_carte_dans_main();
	void affiche(ostream& out, Carte)const;



};

#endif
