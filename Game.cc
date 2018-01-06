#include "Game.hh"

Menu monmenu(WIDTH, HEIGHT);

int GameState =0;

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
        if  ((monmenu.getMenu(0)).getColor() ==  sf::Color::Black){
            if (event.key.code == sf::Keyboard::Numpad1){
                 GameState = 1;
                    }
                }
        }

      
}


void Game::update()
{    
}

void Game::render()
{
    window.clear();
    if (GameState == 1){
        sf::Texture Terrain;
        std::cout << "Bogogoogogogo \n";
        window.clear();
        Terrain.loadFromFile("TerrainCarte.png");
        sf::Sprite spT(Terrain);
        window.draw(spT);
    }

    else monmenu.draw(window);
    window.display();
}
