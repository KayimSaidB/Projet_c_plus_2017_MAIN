#include "Joueur.hh"



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
	
	void Joueur::affiche(ostream& out, Carte carte)const{
		
		std::string chaine = carte.get_nom();
		out << chaine << endl; 
				
	}
	
	void Joueur::pioche_une_carte(){
		_carte_main.push_back(_carte_deck.pop_back());
	}
	
	void Joueur::pose_une_carte(Terrain terrainactuel){
		
		int nbrcarte = get_Nb_carte_main();
		
		choix:
		Carte kayim = choisir_carte_dans_main(std::vector<Carte*>_carte_main)
		
		if (nbrcarte==0)
			return "Vous n'avez plus de carte. Piochez s'en une !";
			
		if(kayim.get_point_action() < this->get_point_action()){
			std:cout <<"Impossible de poser cette carte"<<std::endl;
			goto choix;
		}
				
		else{
			this->pts_action -= kayim.get_point_action();
			terrainactuelle.push_back(kayim);
		}
	}
	void Joueur::declarer_une_attaque(std::string macarte,std::string carteadverse,Terrain actuel){
				
	}
	
	Carte Joueur::choisir_carte_dans_main(std::vector<Carte*>_carte_main){
			
		int choix = 0; // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		int sizecart = get_Nb_carte_main();
		while(choix == 0 && i <= get_Nb_carte_main()){
			affiche(_carte_main[i];
			
			std::cout << "Voulez cette carte ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precdent" <<"\n" ;
			std::cin >> choix;
			
			switch (choix){
				case 1 : 
				Carte tmp = _carte_main[i%sizecart];
				_carte_main.erase(_carte_main.begin()+(i%sizecart));
				return tmp;
				break;
				case 2 : i +=1;
				break;
				case 3 : i-=1;
				break;
			}
		}
			
		
