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
	
	void Joueur::pose_une_carte(Terrain terrainactuel){
		
		int nbrcarte = get_Nb_carte_main();
		
		choix:
		CarteMonstre kayim = choisir_carte_dans_main();
		
		if (nbrcarte==0)
			std::cout << "Vous n'avez plus de carte. Piochez en une !" <<std::endl ;
			return;
			
		if(kayim.get_point_action() < _pts_action){
			std::cout <<"Impossible de poser cette carte"<<std::endl;
			goto choix;
		}
				
		else{
			_pts_action =_pts_action- kayim.get_point_action();
			terrainactuel.push_that_card( &kayim,_numero_joueur);
		}
		
	}
	void Joueur::declarer_une_attaque(std::string macarte,std::string carteadverse,Terrain actuel){
				
	}
	void Joueur::init_deck(){
		_carte_deck.push_back(CarteMonstre("Tao Pai Pai evadé fiscal",10,15,16,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Freezer evadé fiscal",50,1500,1600,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Jiren evadé fiscal",50000,15000,16000,DansDeck,Guerrier));
		int i;
		for (i=0;i<3;i++) _carte_deck[i].affiche();


	}
	CarteMonstre Joueur::choisir_carte_dans_main(){
			
		int choix = 0; // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		int sizecart = get_Nb_carte_main();
		std::cout <<"nb carte main" << std::endl;
		std::cout << sizecart << std::endl;
		while(choix == 0 || i <= get_Nb_carte_main()){
			_carte_main[i].affiche();
			
			std::cout << "Voulez cette carte ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precdent" <<"\n" ;
			std::cin >> choix;
			
			switch (choix){
				case 1 : {
				CarteMonstre tmp = _carte_main[i];
				_carte_main.erase(_carte_main.begin()+(i%sizecart));
				return tmp;
			
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
		//return _carte_main[1];
		}
			
		
