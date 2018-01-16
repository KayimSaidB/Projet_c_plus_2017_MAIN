#include "CarteMonstreE.hh"



CarteMonstreE::CarteMonstreE(std::string nom,int pts_action,int pts_atk,int pdv,Etat mon_etat,Attribut mon_attribut,int indiceffet){
	_nom=nom;
	_pts_action=pts_action;
	_pts_atk=pts_atk;
	_mon_etat=mon_etat;
	_pdv=pdv;
	_mon_attribut=mon_attribut;
	_indiceffet=indiceffet;
}

void set_effet(std::string effet){_effet=effet;}

int get_indice(){return _indiceffet;}


	//}
