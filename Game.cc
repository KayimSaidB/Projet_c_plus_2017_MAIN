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
        Menu monmenu(WIDTH, HEIGHT);

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
                        std::cout << ((monmenu.getMenu(0)).getColor()==sf::Color::Black) <<std::endl;
                        monmenu.draw(window);

                        break;
                    case sf::Keyboard::Down:
                        monmenu.moveDown();
                      std::cout << ((monmenu.getMenu(0)).getColor()==sf::Color::Black) <<std::endl;
                        monmenu.draw(window);

                        break;
                }
            }
        if ((monmenu.getMenu(0)).getColor() ==  sf::Color::Black){
                if (event.key.code == sf::Keyboard::Space){
                   sf::Texture Terrain;
                   Terrain.loadFromFile("Terrain.png");
                    sf::Sprite spT(Terrain);
                    window.draw(spT);
                }
                break;     
        }
    }
    }


void Game::update()
{
}

void Game::render(sf::Menu unmenu)
{
    window.clear();

  //  Menu menu(WIDTH, HEIGHT);
    menu.draw(window);

    window.display();
}
