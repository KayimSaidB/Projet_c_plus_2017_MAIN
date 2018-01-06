#include "Menu.hh"

Menu::Menu(double width, double height)
{
    if (!font.loadFromFile("belwe.ttf"))
    {
        return;
    }

 
    fond.loadFromFile("yugi.png");



    menu[0].setFont(font);
    menu[0].setColor(sf::Color::White);
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
    for (int i = 0; i < MAX_NUMBER_OF_ITMES; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::moveUp()
{
    if (MAX_NUMBER_OF_ITMES - 1 <= selectedItemIndex+1 && selectedItemIndex+1 <= MAX_NUMBER_OF_ITMES)
    { std::cout << selectedItemIndex  << std::endl;
        menu[selectedItemIndex].setColor(sf::Color::White);

        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Black);
        std::cout << selectedItemIndex  << std::endl;

    }
}

void Menu::moveDown()
{
    if (MAX_NUMBER_OF_ITMES - 2 <= selectedItemIndex + 1 && selectedItemIndex + 1 <= MAX_NUMBER_OF_ITMES-1)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Black);
    }
}