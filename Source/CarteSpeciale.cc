#include "Headers/CarteSpeciale.hh"



CarteSpeciale::CarteSpeciale(int pts_action,int indiceffet,int indiceowner){


	_pts_action=pts_action;
	_indiceffet=indiceffet;

	_indiceowner=indiceowner;
	switch (indiceffet){
			case 0: {
					_description="Vous rend 500 point de Vie";
					_nom="Charite Divine";
					break;
			}
			case 1:{
				
				_description="Retire 200 point de vie à votre adversaire";
				_nom="Jalousie Demoniaque";
 				break;
			}

			case 2:{
				
				_description="Detruit toutes les cartes de l'adversaire";
				_nom="L'offensive des Rois";
				break;
			}	
	}
}
 

bool CarteSpeciale::effet_special(Joueur *joueur1,Joueur *joueur2, Terrain *unbeauterrain){
	
if (joueur1->get_point_action()>=_pts_action){
	switch (_indiceffet){
			case 0: {
					joueur1->set_pdv(joueur1->get_pointdevie()+500);
					*joueur1-_pts_action;
					return true;
					break;
			}
			case 1:{
				
				joueur2->set_pdv(joueur2->get_pointdevie()-200);
				*joueur1-_pts_action;
				return true;
 				break;
			}

			case 2:{
				
				unbeauterrain->remove_all(joueur2->get_num());
				*joueur1-_pts_action;
				return true;
				break;
			}	
	}

}
else return false;

}
