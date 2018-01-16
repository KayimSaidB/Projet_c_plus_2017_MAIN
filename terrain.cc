#include "terrain.hh"

	int Terrain::get_nbrtour(){return _nbtour;}
	int Terrain::get_tempstour(){return _temps;}
	std::vector<CarteMonstre> Terrain::get_carte_joueur1(int indice){if (indice==1) return _carte_joueur1;
					else 
						return _carte_joueur2;
	}
	std::vector<CarteMonstre> Terrain::get_carte_joueur2(){return _carte_joueur2;}
	void Terrain::push_that_card( CarteMonstre macarte,int numerojoueur){
		if (numerojoueur==1) {_carte_joueur1.push_back(macarte); 
		}
		
		else _carte_joueur2.push_back(macarte);
		
		}

	
	Terrain::Terrain(int nbtour, int temps){_nbtour=nbtour; _temps=temps;}

	 bool Terrain::attack_enclenche(int attaquant, int attaque, int numerojoueur){
	

	 	if (numerojoueur==1){
	 		if (already_attack1[attaquant]==false){
	 		_carte_joueur2[attaque].set_pdv(_carte_joueur2[attaque].get_pdv()-_carte_joueur1[attaquant].get_pts_atk());	


	 		if (_carte_joueur2[attaque].get_pdv()<0) _carte_joueur2.erase(_carte_joueur2.begin()+attaque);
	 		already_attack1[attaquant]=true;
			return true;
			}
	 	else return false;

	 }
	 		
	 	else {
	 	if (already_attack2[attaquant]==false){

	 		_carte_joueur1[attaque].set_pdv(_carte_joueur1[attaque].get_pdv()-_carte_joueur2[attaquant].get_pts_atk());
	 		if (_carte_joueur1[attaque].get_pdv()<=0) _carte_joueur1.erase(_carte_joueur1.begin()+attaque);
	 		already_attack2[attaquant]=true;

	 		return true;
	 		}
	 	else return false;
	 	}


	 }
	 void Terrain::attack_reinit(int indice){
	 		if (indice==1){
	 			int i;
	 			for (i=0;i<_carte_joueur1.size();i++){
	 			already_attack1[i]=false;
	 		std::cout << "faut qu'on se serre les coude" << std::endl;
	 	}

	 		}
	 		else 	{
	 			int i;
	 			for (i=0;i<_carte_joueur2.size();i++){
	 			already_attack2[i]=false;
	 			std::cout << "faut qu'on se serre les coude" << std::endl;
	 		}
	 	}


	 }
	bool Terrain::already_attack_fun(int indicejoueur,int indicecarte){

	if (indicejoueur==1)
	 			return already_attack1[indicecarte];

	 		
	 		else 	return already_attack2[indicecarte];
	 		

	 	



	}
