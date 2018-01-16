#include "CarteSpeciale.hh"



CarteSpeciale::CarteSpeciale(std::string nom,int pts_action, std::string description,int indiceffet,int indiceowner){

	_nom=nom;
	_pts_action=pts_action;
	_description=description;
	_indiceffet=indiceffet;
	_indiceowner=indiceowner;
}
 

bool CarteSpeciale::effet_special(int indice,Joueur *joueur1,Joueur *joueur2, Terrain *unbeauterrain){
	
if (joueur1->get_point_action()>=_pts_action){
	switch (indice){
			case 1: {
					joueur1->set_pdv(joueur1->get_pointdevie()+500);
					joueur1->set_pa(joueur1->get_point_action()-_pts_action);
					return true;
					break;
			}
			case 2:{
				
				joueur2->set_pdv(joueur2->get_pointdevie()-200);
				joueur1->set_pa(joueur1->get_point_action()-_pts_action);
				return true;
 				break;
			}

			case 3:{
				
				unbeauterrain->remove_all(joueur2->get_num());
				joueur1->set_pa(joueur1->get_point_action()-_pts_action);
				return true;
				break;
			}	
	}

}
else return false;

}