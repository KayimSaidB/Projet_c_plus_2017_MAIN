#include "terrain.hh"

	int ikfe;
	int Terrain::get_nbrtour(){return _nbtour;}
	int Terrain::get_tempstour(){return _temps;}
	std::vector<CarteMonstre> Terrain::get_carte_joueur1(){return _carte_joueur1;}
	std::vector<CarteMonstre> Terrain::get_carte_joueur2(){return _carte_joueur2;}
	void Terrain::push_that_card( CarteMonstre macarte,int numerojoueur){
		if (numerojoueur==1) {_carte_joueur1.push_back(macarte); 
		}
		
		else _carte_joueur2.push_back(macarte);
		
		}

	void Terrain::afficher_terrain (){
		std::cout << "*************************" << std::endl;
		std::cout << "Carte invoqué joueur 1  : " << std::endl;
		int index_joueur1;
		int index_joueur2;
				std::cout << _carte_joueur1.size() << std::endl;

		for (index_joueur1=0;index_joueur1< _carte_joueur1.size();index_joueur1++){
			std::cout << "-----------------" << std::endl;
			_carte_joueur1[index_joueur1].affiche();
			std::cout << "-----------------" << std::endl;


		}
				std::cout << "||||||||VS||||||||||" << std::endl;

		std::cout << "Carte invoqué joueur 2  : " << std::endl;

		for (index_joueur2=0;index_joueur2< _carte_joueur2.size();index_joueur2++){
			std::cout << "-----------------" << std::endl;
			_carte_joueur2[index_joueur2].affiche();
			std::cout << "-----------------" << std::endl;


		}
		std::cout << "*********************" << std::endl;


	}
	Terrain::Terrain(int nbtour, int temps){_nbtour=nbtour; _temps=temps;}

	 void Terrain::attack_enclenche(int attaquant, int attaque, int numerojoueur){
	 	if (numerojoueur==1){
	 		_carte_joueur2[attaque].set_pdv(_carte_joueur2[attaque].get_pdv()-_carte_joueur1[attaquant].get_pts_atk());
	 		if (_carte_joueur2[attaque].get_pdv()<0) _carte_joueur2.erase(_carte_joueur2.begin()+attaque);

	 	}
	 		
	 	else {

	 		_carte_joueur1[attaque].set_pdv(_carte_joueur1[attaque].get_pdv()-_carte_joueur2[attaquant].get_pts_atk());
	 		if (_carte_joueur1[attaque].get_pdv()<=0) _carte_joueur1.erase(_carte_joueur1.begin()+attaque);

	 		}

	 }
