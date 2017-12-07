#include "Carte.h"

class CarteMonstre : public Carte

{protected:
	int pts_atk;
	int pdv;
	Etat mon_etat;
	Attribut mon_attribut;
public:
	std::string get_description();
	std::string get_point_action();
	Attribut get_attribut(); 


};
