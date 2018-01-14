#include "Carte.h"
#ifndef __CARTEMONSTRE_HH
#define __CARTEMONSTRE_HH

class CarteMonstre : public Carte

{protected:
	int _pts_atk;
	int _pdv;
	Etat _mon_etat;
	Attribut _mon_attribut;
	std::string nom;
public:
	std::string get_description() const;
	int get_point_action()const;
	Attribut get_attribut();
	Etat get_etat();
	int get_pts_atk();
	int get_pdv(); 
	void set_pdv(int newpdv);
	std::string get_nom();
	void affiche() const;
	CarteMonstre(std::string nom,int pts_action,int pts_atk,int _pdv,Etat _mon_etat,Attribut _mon_attribut);
   ~CarteMonstre(){};

	std::string affichage()const {

		return _nom+ "\n\n\nPoint de vie : " +std::to_string(_pdv)+" Point d' action : "+std::to_string(_pts_action)+ " Point d'attaque :" +std::to_string(_pts_atk);

	}
};
#endif
