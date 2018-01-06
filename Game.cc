#include "Game.hh"

Menu monmenu(WIDTH, HEIGHT);

Game::Game() : window(sf::VideoMode(WIDTH,HEIGHT),"Welcome To Paradise Papers !")
{
    window.setFramerateLimit(60);

}

void Game::run()

{   


    while (window.isOpen())
    {   
        
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        monmenu.moveUp();
                        monmenu.draw(window);
                        break;
                    case sf::Keyboard::Down:
                        monmenu.moveDown();
                        monmenu.draw(window);
                        break;
                }
            }
        }

      
}


void Game::update()
{
    if  ((monmenu.getMenu(0)).getColor() ==  sf::Color::Black){
            sf::Event event;
                        if (event.key.code == sf::Keyboard::Numpad0){
                            sf::Texture Terrain;
                            std::cout << "Bogogoogogogo \n";
                            window.clear();
                            Terrain.loadFromFile("Terrain.png");
                            sf::Sprite spT(Terrain);
                            window.draw(spT);
                            }
                        }
        else   monmenu.draw(window);
    
}

void Game::render()
{
    window.clear();
 
    monmenu.draw(window);            
    window.display();
}
