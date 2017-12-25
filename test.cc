#include <SFML/Graphics.hpp>

int main()
{
    // Crée la fenêtre principale avec comme titre "Hello World"
    sf::RenderWindow window(sf::VideoMode(1200, 750), "Hello World");

    // Charge un sprite à afficher
    sf::Texture texture;
    sf::Texture texture2;
    texture2.loadFromFile("yugi.png");
    if (!texture.loadFromFile("plage.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture2);
    // Crée un texte
    sf::Font font;
    if (!font.loadFromFile("belwe.ttf"))
    {
        return EXIT_FAILURE;
    }
    sf::Text text("Mohamed fait grave le gars", font, 18);
	
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

	case sf::Event::MouseButtonPressed: 
		i=1;
            break;
        }
	}
        window.clear(); // Efface l'écran
        if (i==0) window.draw(sprite); // Affiche le sprite
	else window.draw(sprite2); 
		
	window.draw(text); // Affiche le texte
        window.display();  // Met à jour la fenêtre
    }
    return EXIT_SUCCESS;



}

