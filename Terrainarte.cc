#include <SFML/Graphics.hpp>
int main(){

	sf::RenderWindow window(sf::VideoMode(800,600),"Paradise Paper");
	sf::Font font;
    if (!font.loadFromFile("belwe.ttf"))
    {
        return EXIT_FAILURE;
    }

	sf::Texture texture1;
    sf::Texture texture2;

    texture1.loadFromFile("StartScreen.png");
	texture2.loadFromFile("TerrainCarte.png");

	if(!texture2.loadFromFile("TerrainCarte.png") && !texture1.loadFromFile("StartScreen.png") )
		{return EXIT_FAILURE;
		}

    sf::Sprite sprite(texture1);
	sf::Sprite sprite2(texture2);

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
            case sf::Event::KeyPressed :
                if(event.key.code == sf::Keyboard::Num1)
                    i=1;
            break;
        }
	}
     
      
        window.clear(); // Efface l'écran
       if (i==0) {
        window.draw(sprite); // Affiche le sprite
       
}
        else window.draw(sprite2);
         window.display();
    }
    return EXIT_SUCCESS;




}