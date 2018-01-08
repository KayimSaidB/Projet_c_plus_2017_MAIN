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

	void Joueur::init_pa(){_pts_action=50;}
	int Joueur::get_Nb_carte_main(){return _carte_main.size();}
	int Joueur::get_Nb_carte_deck(){return _carte_deck.size();}
	int Joueur::get_pointdevie(){return _pointdevie;}
	std::string Joueur::get_nom(){return _nom;}
	
	
	
	void Joueur::pioche_une_carte(){
		srand(time(NULL));
		int sizecart=_carte_deck.size();
		int j=rand()%sizecart;
		CarteMonstre macarte=_carte_deck[j];
		_carte_main.push_back(macarte); 
		_carte_deck.erase(_carte_deck.begin()+j);


	}
	void Joueur::init_deck(){
		 /// maximum de pa
		int maxpdv=300;
		int maxatt=200;
		int maxpa=(maxpdv+maxatt)/10;
		int nbcartedebut=10;
		int equilibrage=((maxpdv+maxatt)/2)*nbcartedebut;
		srand(time(NULL));
  		std::vector<std::string> liste_boy;
  		std::vector<std::string> liste_girl;
  		std::vector<std::string> liste_titres_boy;
  		std::vector<std::string> liste_titres_girl;
		std::vector<std::string> liste_complement;
  		liste_girl={"Isma","Suzanne","Beyonce","Leia","Bulma","Cecile","Rihanna","Anida","Mina","Sophia","Paola","Claire","Ines","Isma","Suzanne","Alexia","Rama","Myriam","Fatine","Colette","Mahshid"}; //8
  		liste_boy={"Harold","Mohamed","Geng","Kayim","Lancelot","Romaric","Fourier","Kendrick","Onizuka","Kenshin","Hilbert","Ayman","Aurelien","Vincent","Boussad","Walid","Damso","Tarik","Stef","Mr Pecheux"}; ///8
  		liste_titres_boy={"Le pourfendeur","Le Dieu","L'empereur","L'elu","Le controleur","Le Chevalier","Le Roi","Le Magicien","Le Choisi","Le Seigneur","Le Dompteur","Le Prince"}; // 8
  		liste_titres_girl={"La pourfendrice","La Deesse","L'imperatrice","L'elue","La controleuse","La Chevaliere","La Reine","La Magicienne","La Choisie","La Princesse","La Domptrice","La Sorciere"}; //8
  		liste_complement={"Des tenebres","Du Soleil","Des flammes","Des toilettes","De l'informatique","Des mathematiques","Des Dragons Noirs aux yeux rouges","Des paradis fiscaux","Des Problemes NP complets","Des Algorithmes Recursifs","Des Ingenieurs","Des Compilateurs","Des banquiers","Des Evades Fiscaux en Suisse","Des Pratiquants de Musculation intensive","Des schemas de Ponzi"}; //9

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
  		for (i=0;i<nbcartedebut/2;i++){ /// boucle des garcons
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
			_pts_action =_pts_action- kayim.get_point_action();
			terrainactuel->push_that_card( kayim,_numero_joueur);
			std::cout << choix << std::endl;
			std::cout << sizecart << std::endl;

			_carte_main.erase(_carte_main.begin()+(choix%sizecart));
			return true;
			
			
		}
		//return _carte_main[1];
		}
			
		
