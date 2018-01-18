#ifndef __CARTESPECIALE_HH
#define __CARTESPECIALE_HH
#include <iostream>
#include <string>
#include "Carte.h"
#include "CarteMonstre.h"
#include "terrain.hh"
#include "Joueur.hh"



class CarteSpeciale : public Carte {

protected:
//int _pts_action;///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
std::string _description;
//std::string _nom;
int _indiceffet;
int _indiceowner; /// indice du joueur a qui appartient la carte
public:
 std::string get_description() const {return _description;};
 CarteSpeciale(std::string nom,int pts_action, std::string description,int indiceeffet,int indiceowner);
 int get_point_action() const{return _pts_action;};
 std::string affichage() const {return "Nom de la carte speciale : "+_nom +"\n\n"+_description+" Point d'action : "+std::to_string(_pts_action);};
 std::string get_nom() const{return _nom;};
 bool effet_special(int indice,Joueur *joueur1,Joueur *joueur2, Terrain *unbeauterrain);
 int get_indice_effet(){return _indiceffet;};
};
#endif