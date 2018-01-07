#include "Menu.hh"

Menu::Menu(double width, double height)
{
    if (!font.loadFromFile("belwe.ttf"))
    {
        return;
    }

 
    fond.loadFromFile("yugitkt.png");



    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Black);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITMES + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITMES + 1) * 2));
}


void Menu::draw(sf::RenderWindow &window)
{	
    sf::Sprite spf(fond);
	window.draw(spf);

     sf::Text text("Choix avec ESAPCE", font, 13);
    text.setPosition(10,250);
    window.draw(text);
    for (int i = 0; i < MAX_NUMBER_OF_ITMES; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::moveUp()
{
    if (selectedItemIndex == 1)
    { std::cout << selectedItemIndex  << std::endl;
        menu[selectedItemIndex].setColor(sf::Color::White);

        selectedItemIndex = 0;
        menu[selectedItemIndex].setColor(sf::Color::Black);
        std::cout << selectedItemIndex  << std::endl;

    }
}

void Menu::moveDown()
{
    if (selectedItemIndex == 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex = 1;
        menu[selectedItemIndex].setColor(sf::Color::Black);
        std::cout << selectedItemIndex  << std::endl;
    }
}