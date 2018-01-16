#ifndef __JOUEUR_HH
#define __JOUEUR_HH
#include <iostream>
#include <string>
#include <vector>
#include "CarteMonstre.h"
#include "terrain.hh"
#include "Element.hh"
//#include "CarteSpeciale.hh"
class Joueur : public Element {

protected:
 ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
int _pointdevie;
std::string _nom;
std::vector<CarteMonstre> _carte_main;
std::vector<CarteMonstre> _carte_deck;
int _numero_joueur;
public:
	Joueur(int pts_action,int pointdevie,std::string nom,int numero_joueur);
    ~Joueur(){};
	int get_point_action() const;
	int get_Nb_carte_main();
	int get_Nb_carte_deck();
	int get_pointdevie(); 
	std::string get_nom () const ;
	void pioche_une_carte();
	//void pose_une_carte(Terrain terrainactuel);
	void declarer_une_attaque(Terrain *actuel,int choix);
	bool choisir_carte_dans_main_et_poser(Terrain *terrainactuel, int choix);
	void init_deck();
	void init_deck2();
	void init_main();
	void init_pa();
	std::vector<CarteMonstre> get_main(){return _carte_main;};
	int get_num(){return _numero_joueur;};
	void set_pdv(int newpdv){_pointdevie=newpdv;}
	void set_pa(int newpa){_pts_action=newpa;}
	std::string affichage()const {	return _nom+ "\n\nPoint de vie : " +std::to_string(_pointdevie)+"\n\nPoint d' action : "+std::to_string(_pts_action);



	}

};

#endif
