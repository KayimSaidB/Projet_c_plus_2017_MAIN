#include "Joueur.hh"



Joueur::Joueur(int pts_action,int pointdevie,std::string nom,int numero_joueur){
	_nom=nom;
	_pts_action=pts_action;
	_pointdevie=pointdevie;
	_numero_joueur=numero_joueur;
}
	
	int Joueur::get_point_action(){return _pts_action;}


	int Joueur::get_Nb_carte_main(){return _carte_main.size();}
	int Joueur::get_Nb_carte_deck(){return _carte_deck.size();}
	int Joueur::get_pointdevie(){return _pointdevie;}
	std::string Joueur::get_nom(){return _nom;}
	
	
	
	void Joueur::pioche_une_carte(){
		CarteMonstre macarte=_carte_deck.back();
		_carte_deck.pop_back();
		_carte_main.push_back(macarte); 


	}
	
	/*void Joueur::pose_une_carte(Terrain terrainactuel){
		
		int nbrcarte = get_Nb_carte_main();
		
		choix:
		CarteMonstre kayim = choisir_carte_dans_main();
		
		if (nbrcarte==0)
			std::cout << "Vous n'avez plus de carte. Piochez en une !" <<std::endl ;
			return;
			

		
	}*/
	void Joueur::declarer_une_attaque(Terrain *terrainactuel)
	{	
int attaque,attaquant;
if (_numero_joueur==1){
	///CAS OU joueur 1 attaque joueur 2
		int choix = 0; // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		bool cestbon=false;
		std::cout << "l'attaque s'enclenhce hf" << std::endl;

		while(choix == 0 || i <= (terrainactuel->get_carte_joueur1()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur1())[i]).affiche();
			std::cout << "Avec quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			std::cin >> choix;
			switch (choix){
				case 1 : {
		    attaquant = i;
			std::cout << "l'attaque s'enclenhce attaquant" << std::endl;
	 		 	
	 		 	std::cout << attaquant << std::endl;
			cestbon=true;
			break;
			
				}
				
				case 2 : {
					i +=1;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i-=1;
						std::cout << "okaay" << std::endl;

				break;
			}
			}

		}
			cestbon=false; i=0;
			while(choix == 0 || i <= (terrainactuel->get_carte_joueur2()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur2())[i]).affiche();
			std::cout << "Quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			std::cin >> choix;
			switch (choix){
				case 1 : {
			attaque = i;
			cestbon=true;
			std::cout << "l'attaque s'enclenhce tkt" << std::endl;
			std::cout << attaquant << std::endl;
			std::cout << attaque<< std::endl;
			std::cout << "l'attaque s'enclenhce tkt" << std::endl;

			terrainactuel->attack_enclenche(attaquant,attaque,_numero_joueur);

			break;
			break;
				}
				
				case 2 : {
					i +=1;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i-=1;
				break;
			}
			}
}

}
else {
	///CAS OU joueur 2 attaque joueur 1

		int choix = 0; // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		bool cestbon=false;
		std::cout << "l'attaque s'enclenhce hf" << std::endl;

		while(choix == 0 || i <= (terrainactuel->get_carte_joueur2()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur2())[i]).affiche();
			std::cout << "Avec quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			std::cin >> choix;
			switch (choix){
				case 1 : {
			 attaquant = i;
	 		 	std::cout << attaquant << std::endl;
			cestbon=true;
			break;
			break;
				}
				
				case 2 : {
					i +=1;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i-=1;
				break;
			}
			}

		}
		cestbon=false;
			while(choix == 0 || i <= (terrainactuel->get_carte_joueur1()).size() && cestbon ==false){
			((terrainactuel->get_carte_joueur1())[i]).affiche();
			std::cout << "Quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			std::cin >> choix;
			switch (choix){
				case 1 : {
			 attaque = i;

			cestbon=true;
			terrainactuel->attack_enclenche(attaquant,attaque,_numero_joueur);

			break;
			break;
				}
				
				case 2 : {
					i +=1;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i-=1;
				break;
			}
			}
}
//terrainactuel->attack_enclenche(attaquant,attaque,_numero_joueur);

}


}


				
	
	void Joueur::init_deck(){
		_carte_deck.push_back(CarteMonstre("Tao Pai Pai evadé fiscal",10,15,16,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Freezer evadé fiscal",50,1500,1600,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Jiren evadé fiscal",50000,15000,16000,DansDeck,Guerrier));
		
	}
void Joueur::init_deck2(){
		_carte_deck.push_back(CarteMonstre("Goku petit evadé fiscal",10,15,16,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Goku Ssj 1 evadé fiscal",50,1500,1600,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Goku Ultra Instinct evadé fiscal",50000,15000,16000,DansDeck,Guerrier));
		
	}


	void Joueur::choisir_carte_dans_main_et_poser(Terrain *terrainactuel){
			
		int choix = 0; // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		int sizecart = get_Nb_carte_main();
		while(choix == 0 || i <= _carte_main.size()){
			_carte_main[i%sizecart].affiche();
			
			std::cout << "Voulez cette carte ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precdent" <<"\n" ;
			std::cin >> choix;
			
			switch (choix){
				case 1 : {
			CarteMonstre kayim = _carte_main[i];
			std::cout << _pts_action <<std::endl;

			if(kayim.get_point_action() > _pts_action){
			std::cout <<"Impossible de poser cette carte"<<std::endl;
			std::cout <<" Plus assez de point d'action" << std::endl;
			break;
				}
				
			else{
			_pts_action =_pts_action- kayim.get_point_action();
			terrainactuel->push_that_card( kayim,_numero_joueur);
			std::cout <<" work" << std::endl;

			_carte_main.erase(_carte_main.begin()+(i%sizecart));
			return;
			break;


					}
					} 
				case 2 : {
					i +=1;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i-=1;
						std::cout << "okaay" << std::endl;
				break;
			}
			}
		}
		//return _carte_main[1];
		}
			
		
