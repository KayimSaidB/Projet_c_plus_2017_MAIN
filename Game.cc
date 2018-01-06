#include "Game.hh"

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
        /*case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.moveUp();
                        break;
                    case sf::Keyboard::Down:
                        menu.moveDown();
                        break;
                }
        case menu.menu[0].getColor() == "Black":
                if (event.key.code == sf::Keyboard::Space){
                   sf::Texture Terrain;
                   Terrain.loadFromFile("Terrain.png");
                    sf::Sprite spT(Terrain);
                    window.draw(spT);
                }
                break; */       
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    window.clear();

    Menu menu(WIDTH, HEIGHT);
    menu.draw(window);

    window.display();
}
