#include <iostream>
#include <string>
#ifndef __CARTE_HH
#define __CARTE_HH

enum Etat{Nonref,SurTerrain,DansMain,DansDeck,DansCimetiere};
enum Attribut{Guerrier,Mage,Paladin};//Guerrier +atq Mage+pdv Paladin Equilibre

class Carte {

protected:
int _pts_action ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
std::string _description;
std::string _nom;

public:
virtual std::string get_description() const=0;
virtual std::string get_point_action() const=0;


};
#endif