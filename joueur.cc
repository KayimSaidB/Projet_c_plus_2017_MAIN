#include "Joueur.hh"
#include <cstdlib>
#include <time.h>       /* time */

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
	void Joueur::declarer_une_attaque(Terrain *terrainactuel, int choix)
	{	
int attaque,attaquant,size;
if (_numero_joueur==1){
	///CAS OU joueur 1 attaque joueur 2
		 // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		bool cestbon=false;
		std::cout << "l'attaque s'enclenhce hf" << std::endl;
		 size=(terrainactuel->get_carte_joueur1()).size();
		while(choix == 0 || i <= (terrainactuel->get_carte_joueur1()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur1())[i]).affiche();
			std::cout << "Avec quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			switch (choix){
				case 1 : {
		    attaquant = i;
			std::cout << "l'attaque s'enclenhce attaquant" << std::endl;
	 		 	
	 		 	std::cout << attaquant << std::endl;
			cestbon=true;
			break;
			
				}
				
				case 2 : {
					i =(i+1)%size;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i=(i-1)%size;
						std::cout << "okaay" << std::endl;

				break;
			}
			}

		}
			cestbon=false; i=0;
			while(choix == 0 || i <= (terrainactuel->get_carte_joueur2()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur2())[i]).affiche();
			size=(terrainactuel->get_carte_joueur2()).size();
			std::cout << "Quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
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
					i=(i+1)%size;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i=(i-1+size)%size;
				break;
			}
			}
}

}
else {
	///CAS OU joueur 2 attaque joueur 1

		 // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;
		int i = 0;
		bool cestbon=false;
		std::cout << "l'attaque s'enclenhce hf" << std::endl;
		size=(terrainactuel->get_carte_joueur2()).size();
		while(choix == 0 || i <= (terrainactuel->get_carte_joueur2()).size() && cestbon==false){
			((terrainactuel->get_carte_joueur2())[i]).affiche();
			std::cout << "Avec quelle carte souhaitez vous attaquer ?" << "\n" << "1 - Oui "<< "\n"<< "\n"<< "2- Suivant"<< "\n"<< "3- Precedent" <<"\n" ;
			switch (choix){
				case 1 : {
			 attaquant = i;
	 		 	std::cout << attaquant << std::endl;
			cestbon=true;
			break;
			break;
				}
				
				case 2 : {
					i =(i+1)%size;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i=(i-1+size)%size;
				break;
			}
			}

		}
		cestbon=false;
			while(choix == 0 || i <= (terrainactuel->get_carte_joueur1()).size() && cestbon ==false){
			((terrainactuel->get_carte_joueur1())[i]).affiche();
			size=(terrainactuel->get_carte_joueur1()).size();
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
					i=(i+1)%size;
					std::cout << "okaay" << std::endl;
				break;
						}
				case 3 : 
				{
						i=(i-1+size)%size;
				break;
			}
			}
}
//terrainactuel->attack_enclenche(attaquant,attaque,_numero_joueur);

}


}


				
	
	void Joueur::init_deck(){
		 /// maximum de pa
		int maxpdv=300;
		int maxatt=200;
		int maxpa=(maxpdv+maxatt)/10;
		int nbcartedebut=10;
		int equilibrage=((maxpdv+maxatt)/2)*nbcartedebut;
		//_carte_deck.push_back(CarteMonstre("Tao Pai Pai evadé fiscal",10,15,16,DansDeck,Guerrier));
		//_carte_deck.push_back(CarteMonstre("Freezer evadé fiscal",50,1500,1600,DansDeck,Guerrier));
		//_carte_deck.push_back(CarteMonstre("Jiren evadé fiscal",50000,15000,16000,DansDeck,Guerrier));
		srand(time(NULL));
  		std::vector<std::string> liste_boy;
  		std::vector<std::string> liste_girl;
  		std::vector<std::string> liste_titres_boy;
  		std::vector<std::string> liste_titres_girl;
		std::vector<std::string> liste_complement;
  		liste_girl={"Isma","Suzanne","Beyonce","Leia","Bulma","Simone","Elizabeth","Serena"}; //8
  		liste_boy={"Harold","Mohamed","Geng","Kayim","Lancelot","Romaric","Fourier","Kendrick"}; ///8
  		liste_titres_boy={"Le pourfendeur","Le Dieu","L'empereur","L'elu","Le controleur","Le Chevalier","Le Roi","Le Magicien"}; // 8
  		liste_titres_girl={"La pourfendrice","La Deesse","L'impératrice","L'elue","La controleuse","La Chevaliere","La Reine","La Magicienne"}; //8
  		liste_complement={"Des ténébres","Du Soleil","Des flammes","Des toilettes","De l'informatique","Des mathématiques","Des Dragons Noirs aux yeux rouges","Des paradis fiscaux","Des Problemes NP complets"}; //9
  		
  		int i=0;
  		for (i=0;i<nbcartedebut/2;i++){ /// boucle des filles
  			int indiceprenom=rand()%liste_girl.size();
  			int indicetitres=rand()%liste_titres_girl.size();
  			int indicecompl=rand()%liste_complement.size();
  			std::string lenom;
  			lenom=liste_girl[indiceprenom]+" "+ liste_titres_girl[indicetitres]+" "+liste_complement[indicecompl];
  			int nbatt=rand()%maxatt;
  			int nbpdv=rand()%maxpdv;
  			do{
  				 nbatt=rand()%maxatt;
  				 nbpdv=rand()%maxpdv;
  				}
  			while (equilibrage<nbatt+nbpdv);
  		    equilibrage=equilibrage-nbatt-nbpdv;
  			int nb_pa=(nbatt+nbpdv)/10;
			_carte_deck.push_back(CarteMonstre(lenom,nb_pa,nbatt,nbpdv,DansDeck,Guerrier));

  		}
  		for (i=0;i<nbcartedebut/2;i++){ /// boucle des filles
  			int indiceprenom=rand()%liste_boy.size();
  			int indicetitres=rand()%liste_titres_boy.size();
  			int indicecompl=rand()%liste_complement.size();
  			std::string lenom;
  			lenom=liste_boy[indiceprenom]+" "+ liste_titres_boy[indicetitres]+" "+liste_complement[indicecompl];
  			int nbatt=rand()%maxatt;
  			int nbpdv=rand()%maxpdv;
  			do{
  				 nbatt=rand()%maxatt;
  				 nbpdv=rand()%maxpdv;
  				}
  			while (equilibrage<nbatt+nbpdv);
  		    equilibrage=equilibrage-nbatt-nbpdv;
  			int nb_pa=(nbatt+nbpdv)/10;
			_carte_deck.push_back(CarteMonstre(lenom,nb_pa,nbatt,nbpdv,DansDeck,Guerrier));

  		}

	}
void Joueur::init_deck2(){
		_carte_deck.push_back(CarteMonstre("Goku petit evadé fiscal",10,15,16,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Goku Ssj 1 evadé fiscal",50,1500,1600,DansDeck,Guerrier));
		_carte_deck.push_back(CarteMonstre("Goku Ultra Instinct evadé fiscal",50000,15000,16000,DansDeck,Guerrier));
		
	}


	bool Joueur::choisir_carte_dans_main_et_poser(Terrain *terrainactuel,int choix){
			int sizecart=_carte_main.size();
			std::cout <<"sizecart"<< std::endl;
			std::cout << sizecart << std::endl;

		 // choix de la carte 0 si egale à 1 alors on sort de la boucle et en retourne la carte;

			
		
			CarteMonstre kayim = _carte_main[choix];
			if(kayim.get_point_action() > _pts_action){
			std::cout <<"Impossible de poser cette carte"<<std::endl;
			std::cout <<" Plus assez de point d'action" << std::endl;
			return false;
				}
				
			else{
			std::cout << "kk" << std::endl;
			_pts_action =_pts_action- kayim.get_point_action();
			terrainactuel->push_that_card( kayim,_numero_joueur);
			std::cout << "kk" << std::endl;
			std::cout << choix << std::endl;
			std::cout << sizecart << std::endl;

			_carte_main.erase(_carte_main.begin()+(choix%sizecart));
			return true;
			
			
		}
		//return _carte_main[1];
		}
			
		
