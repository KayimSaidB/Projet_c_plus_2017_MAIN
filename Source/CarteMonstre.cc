#include "Headers/CarteMonstre.h"



CarteMonstre::CarteMonstre(std::string nom,int pts_action,int pts_atk,int pdv,Etat mon_etat,Attribut mon_attribut){
	_nom=nom;
	_pts_action=pts_action;
	_pts_atk=pts_atk;
	_mon_etat=mon_etat;
	_pdv=pdv;
	_mon_attribut=mon_attribut;
}


	std::string CarteMonstre::get_description() const {return _description;}
 	int CarteMonstre::get_point_action  () const {return _pts_action;}
	Attribut CarteMonstre::get_attribut(){return _mon_attribut;}
	Etat CarteMonstre::get_etat(){return _mon_etat;}
	int CarteMonstre::get_pts_atk(){return _pts_atk;}
	int CarteMonstre::get_pdv(){return _pdv;}
	void CarteMonstre::set_pdv(int newpdv){_pdv=newpdv;			std::cout << "changement pdv" << std::endl;
				std::cout << _pdv << std::endl;

}
	std::string CarteMonstre::get_nom() const {return _nom;}
	//std::vector<Carte*>CarteMonstre::generate_deck(){
	void CarteMonstre::affiche()const{
		
		
		std::cout <<"Nom : " << _nom <<std::endl; 
		std::cout <<"Point de vie : " << _pdv <<std::endl;
		std::cout <<"Point d'attaque :" << _pts_atk <<std::endl; 
		std::cout <<"Point d'action : " << _pts_action <<std::endl; 

 

				
	}


	//}