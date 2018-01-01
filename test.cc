#include <SFML/Graphics.hpp>
int main()
{
    // Crée la fenêtre principale avec comme titre "Hello World"
    sf::RenderWindow window(sf::VideoMode(1200, 750), "Hello World");

    // Charge un sprite à afficher
    sf::Texture texture;
    sf::Texture texture2;
    texture2.loadFromFile("yugi.png");
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texture5;
    texture3.loadFromFile("evasioncarte.jpg");
    texture4.loadFromFile("evasion_invoque.png");
    texture5.loadFromFile("doscarte.png");
    if (!texture.loadFromFile("plage.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);
    sf::Sprite sprite5(texture5);
    sprite3.setColor(sf::Color(0, 255, 0));
    //sprite3.setRotation(90); // angle absolu
    //sprite3.resize(0.5,0.5);
    sprite3.scale(sf::Vector2f(0.1f, 0.1f));
    sprite3.setPosition(sf::Vector2f(10, 50)); // position absolue
    sprite4.scale(sf::Vector2f(0.1f, 0.1f));
    sprite4.setPosition(sf::Vector2f(10, 100));
    sprite5.scale(sf::Vector2f(0.1f, 0.1f));
    sprite5.setPosition(sf::Vector2f(1000,600));
     // facters d'échelle relatifs à l'échelle actuelle    // Crée un texte
    sf::Font font;
    if (!font.loadFromFile("belwe.ttf"))
    {
        return EXIT_FAILURE;
    }
    sf::Text text("Mohamed fait grave le gars", font, 13);
    text.setPosition(10,250);
	
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
                sprite3.move(sf::Vector2f(15, 0)); // décalage relatif à la position actuelle        
                    break;
        }
	}
        window.clear(); // Efface l'écran
        if (i==0) {
        window.draw(sprite); // Affiche le sprite
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
}
    else window.draw(sprite2); 
		
	window.draw(text); // Affiche le texte
        window.display();  // Met à jour la fenêtre
    }
    return EXIT_SUCCESS;



}

