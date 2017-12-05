#include <iostream>
#include <string>
enum Etat{Nonref,SurTerrain,DansMain,DansDeck,DansCimetiere};
class Carte {

protected:
int point_action; ///Indique le nombre de point d'action nécéssaire à  l'utilisation de la carte
std::string description;
public:
virtual std::string get_description() const=0;
virtual std::string get_point_action() const=0;


};
