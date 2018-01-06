#ifndef __MENU_HH
#define __MENU_HH
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#pragma once
#define MAX_NUMBER_OF_ITMES 2



class Menu
{
public:
    Menu(double witdh, double height);
    //~Menu();
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() { return selectedItemIndex; };
    sf::Text getMenu(int i){return menu[i];}

    int selectedItemIndex = 1;

private:
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITMES];
    sf::Texture fond;


};
#endif