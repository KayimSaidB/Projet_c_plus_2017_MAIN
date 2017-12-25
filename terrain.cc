#include "terrain.hh"

	int Terrain::get_nbrtour(){return _nbtour;}
	int Terrain::get_tempstour(){return _temps;}
	void Terrain::push_that_card( Carte* macarte,int numerojoueur){
		if (numerojoueur==1) _carte_joueur1.push_back(macarte);
		
		else _carte_joueur2.push_back(macarte);
		
		}

	void Terrain::afficher_terrain (){

	}
	 
