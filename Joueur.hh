#ifndef __JOUEUR_HH
#define __JOUEUR_HH
#include <iostream>
#include <string>
#include <vector>
#include "CarteMonstre.h"
#include "terrain.hh"
class Joueur {

protected:
int _pts_action; ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
int _pointdevie;
std::string _nom;
std::vector<CarteMonstre> _carte_main;
std::vector<CarteMonstre> _carte_deck;
int _numero_joueur;
public:
	Joueur(int pts_action,int pointdevie,std::string nom,int numero_joueur);
	int get_point_action();
	int get_Nb_carte_main();
	int get_Nb_carte_deck();
	int get_pointdevie(); 
	std::string get_nom();
	void pioche_une_carte();
	void pose_une_carte(Terrain terrainactuel);
	void declarer_une_attaque(std::string macarte,std::string carteadverse,Terrain actuel);
	CarteMonstre choisir_carte_dans_main();
	void init_deck();
	void init_main();


};

#endif
