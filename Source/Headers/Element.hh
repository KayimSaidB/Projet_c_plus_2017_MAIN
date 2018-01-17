#include <iostream>
#include <string>
#ifndef __ELEMENT_HH
#define __ELEMENT_HH



class Element {

protected:
int _pts_action;/// nombre de point d'action 
//std::string _description;
std::string _nom;

public:
virtual int get_point_action() const=0;
virtual std::string affichage() const=0;
virtual std::string get_nom() const=0;
};
#endif