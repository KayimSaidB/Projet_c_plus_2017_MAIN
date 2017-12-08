#include "joueur.hh"



Joueur::Joueur(int pts_action,int pointdevie,std::string nom;){
	_nom=nom;
	_pts_action=pts_action;
	_pointdevie=pointdevie;
	
}
	
	int Joueur::get_point_action(){return _pts_action;}


	int Joueur::get_Nb_carte_main(){return _carte_main.size();}
	int Joueur::get_Nb_carte_deck(){return _carte_deck.size()}
	int Joueur::get_pointdevie(){return _pointdevie}
	std::string Joueur::get_nom(){return _nom}
	void Joueur::pioche_une_carte(){



	}
	void Joueur::pose_une_carte(std::string macarte, Terrain terrainactuel){


	}
	void Joueur::declarer_une_attaque(std::string macarte,std::string carteadverse,Terrain actuel){

		
	}
