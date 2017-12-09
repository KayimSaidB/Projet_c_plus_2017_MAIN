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
	std::string get_description();
	int get_point_action();
	Attribut get_attribut();
	Etat get_etat();
	int get_pts_atk();
	int get_pdv(); 
	
	CarteMonstre(std::string nom,int pts_action,int pts_atk,int _pdv,Etat _mon_etat,Attribut _mon_attribut);

};
#endif
