#include "Joueur.hh"

int main(){


	Joueur untypebien(200000000,700,"Mohamed",1);
	Joueur unsecondtypebien(20000000,700,"Harold",2);
	Terrain unbeauterrain(0,0);
	untypebien.init_deck();
	unsecondtypebien.init_deck2();
	untypebien.pioche_une_carte();
	untypebien.pioche_une_carte();
	untypebien.pioche_une_carte();
	unsecondtypebien.pioche_une_carte();
	unsecondtypebien.pioche_une_carte();
	unsecondtypebien.pioche_une_carte();
	untypebien.choisir_carte_dans_main_et_poser(&unbeauterrain);
	unbeauterrain.afficher_terrain();
	unsecondtypebien.choisir_carte_dans_main_et_poser(&unbeauterrain);
	unbeauterrain.afficher_terrain();
	unsecondtypebien.choisir_carte_dans_main_et_poser(&unbeauterrain);
	unbeauterrain.afficher_terrain();
	untypebien.declarer_une_attaque(&unbeauterrain);
	unbeauterrain.afficher_terrain();
	unsecondtypebien.declarer_une_attaque(&unbeauterrain);
	unbeauterrain.afficher_terrain();

	return 1;
}
