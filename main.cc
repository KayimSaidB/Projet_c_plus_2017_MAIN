#include "Joueur.hh"

int main(){


	Joueur untypebien(20,700,"Mohamed",1);
	untypebien.init_deck();
	std::cout << untypebien.get_point_action() << std::endl;
	untypebien.pioche_une_carte();
	untypebien.pioche_une_carte();
	untypebien.pioche_une_carte();
	CarteMonstre carteaposer=untypebien.choisir_carte_dans_main	();
		std::cout << "Premiere fonction" << std::endl;

	CarteMonstre carteaposer2=untypebien.choisir_carte_dans_main();
	std::cout << "Seconde fonction" << std::endl;

	CarteMonstre carteaposer3=untypebien.choisir_carte_dans_main();

	return 1;
}
