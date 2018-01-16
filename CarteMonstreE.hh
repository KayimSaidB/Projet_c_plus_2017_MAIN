#include "Carte.h"
#include "CarteMonstre.h"

#ifndef __CARTEMONSTREE_HH
#define __CARTEMONSTREE_HH

class CarteMonstreE : public CarteMonstre

{protected:
	std::string _effet;
	int _indiceffet;
public:
void set_effet(std::string effet);
int get_indice();
	CarteMonstreE(std::string nom,int pts_action,int pts_atk,int _pdv,Etat _mon_etat,Attribut _mon_attribut,int indiceffet);
   ~CarteMonstreE(){};
	std::string affichage()const {

		return _nom+ "\n\n\nPoint de vie : " +std::to_string(_pdv)+" Point d' action : "+std::to_string(_pts_action)+ " Point d'attaque :" +std::to_string(_pts_atk)+ _effet;

	}

};
#endif
