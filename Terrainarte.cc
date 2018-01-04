#include <SFML/Graphics.hpp>
int main(){

	sf::RenderWindow window(sf::VideoMode(800,600),"Paradise Paper");
	sf::Font font;
    if (!font.loadFromFile("belwe.ttf"))
    {
        return EXIT_FAILURE;
    }

	sf::Texture texture1;
	texture1.loadFromFile("TerrainCarte.png");

	if(!texture1.loadFromFile("TerrainCarte.png"))
		{return EXIT_FAILURE;
		}


	sf::Sprite sprite(texture1);

 // Boucle principale
int i=0;
    while (window.isOpen())
    {	
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event))
        {

	switch(event.type){
            // Fermeture de la fenêtre
            case sf::Event::Closed:
            	
                window.close();
            	break;

	//case sf::Event::MouseButtonPressed: 
      //          sprite3.move(sf::Vector2f(15, 0)); // décalage relatif à la position actuelle        
                   break;
        }
	}
        window.clear(); // Efface l'écran
        if (i==0) {
        window.draw(sprite); // Affiche le sprite
}
	
        window.display();  // Met à jour la fenêtre
    }
    return EXIT_SUCCESS;




}