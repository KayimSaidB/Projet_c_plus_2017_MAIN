#include <iostream>
#include <string>
#include <vector>
#include "Carte.h"
class Joueur {

protected:
int _pts_action ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
int _pointdevie;
std::string _nom;
std::vector<Carte*> carte_main;
std::vector<Carte*> carte_deck;

public:
	int get_point_action();
	int get_Nb_carte_main();
	int get_Nb_carte_deck();
	int get_pointdevie(); 
	std::string get_nom();
	void pioche_une_carte(std::string macarte);
	void pose_une_carte(std::string macarte);
	void declarer_une_attaque(std::string macarte);



};