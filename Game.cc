#include "Game.hh"
#include <cstdlib>
#include <time.h>
#include <sstream>
Menu monmenu(WIDTH, HEIGHT);

int GameState =0;
int h=4;
int indicecarteivo;
int indicecarteattaquant=0;
int indicecarteattaque=0;
Game::Game() : window(sf::VideoMode(WIDTH,HEIGHT),"Welcome To Paradise Papers !")
{
    window.setFramerateLimit(60);

}

void Game::run()

{   
  Joueur untypebien(50,700,"Mohamed",1);
  Joueur unsecondtypebien(20000000,700,"Harold",2);
  Terrain unbeauterrain(0,0); 
    while (window.isOpen())
    {   
        
        processEvents(&untypebien,&unsecondtypebien,&unbeauterrain);
        update(&untypebien,&unsecondtypebien,&unbeauterrain);
        render(&untypebien,&unsecondtypebien,&unbeauterrain);
    }
}

void Game::processEvents(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{
    sf::Event event;
    int vache=0;
    
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if(GameState == 0){
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
             if (GameState==3){
                switch (event.key.code){
                    case sf::Keyboard::Space:
                        vache=3; //invocation
                        break;

                    case sf::Keyboard::Right:
                        indicecarteivo=(indicecarteivo+1+joueur1->get_Nb_carte_main())%joueur1->get_Nb_carte_main();
                    std::cout <<"on repete les" <<std::endl;
                        break;
                    case sf::Keyboard::Left:
                        indicecarteivo=(indicecarteivo-1+joueur1->get_Nb_carte_main())%joueur1->get_Nb_carte_main();
                                            std::cout <<"on repete les" <<std::endl;

                        break;
                    }
             }
            }
        if  ((monmenu.getMenu(0)).getColor() ==  sf::Color::Black){
            if (event.key.code == sf::Keyboard::Space){
                 GameState = 1;
                    }
                }

        if  ((monmenu.getMenu(1)).getColor() ==  sf::Color::Black){
            if (event.key.code == sf::Keyboard::Space){
                GameState = 2;
                    }
                }
        if (vache==3)
            {     std::cout << "quand vache" << std::endl;

                 std::cout << joueur1->get_Nb_carte_main() << std::endl;

                GameState=4;}
        }

      
}


void Game::update(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{ 
      

if (GameState == 1 && h==4){
    std::cout << "image de soi meme" <<std::endl;
        std::cout << GameState <<std::endl;
    std::cout << "image de soi meme" <<std::endl;


    joueur1->init_deck();
    joueur2->init_deck();
    joueur1->pioche_une_carte();
    joueur1->pioche_une_carte();
    joueur1->pioche_une_carte();
    joueur1->pioche_une_carte();

    joueur2->pioche_une_carte();
    joueur2->pioche_une_carte();
    joueur2->pioche_une_carte();
    h=5;

}
if (GameState==4){
    std::cout << "lourd bail" << std::endl;
    std::cout << joueur1->get_Nb_carte_main() << std::endl;

        if (joueur1->choisir_carte_dans_main_et_poser(unbeauterrain,indicecarteivo)==false){

            GameState=3;
            h=3;
        }
        else {h=2;}

GameState=3;

}



}

void Game::render(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{   
    sf::Font font;
    font.loadFromFile("belwe.ttf");
    window.clear();
    if (GameState == 1 || GameState ==3){
        GameState=3;
        std::cout << joueur1->get_Nb_carte_main() << std::endl;

        sf::Texture Terrain;
        ///std::cout << "Bogogoogogogo \n";
        window.clear();
        Terrain.loadFromFile("TerrainCarte.png");
        sf::Sprite spT(Terrain);
        window.draw(spT);
        sf::Texture pioche;
        pioche.loadFromFile("doscarte.png");
        sf::Sprite spritepioche(pioche);
        spritepioche.scale(sf::Vector2f(0.15f, 0.15f));
        spritepioche.setPosition(sf::Vector2f(675, 500)); 
        sf::Sprite spritepioche2(pioche);
        spritepioche2.scale(sf::Vector2f(0.15f, 0.15f));
        spritepioche2.setPosition(sf::Vector2f(185, 135)); 
        spritepioche2.setRotation(180);
        window.draw(spritepioche);
        window.draw(spritepioche2);
        int i;
        sf::Texture cartemain;
        cartemain.loadFromFile("evasioncarte.jpg");
        sf::Texture carteterrain;
        carteterrain.loadFromFile("evasion_invoque.png");
        for (i=0;i<joueur1->get_Nb_carte_main();i++){
        std::cout << joueur1->get_Nb_carte_main ()<< std::endl;
        sf::Sprite cartetemp(cartemain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(454-i*70, 485));
        int rouge=(joueur1->get_main())[i].get_pts_atk();
        int bleu=(joueur1->get_main())[i].get_pdv();
        int vert=(joueur1->get_main())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
      for (i=0;i<unbeauterrain->get_carte_joueur1().size();i++){
        sf::Sprite cartetemp(carteterrain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(454-i*100,305));
        int rouge=unbeauterrain->get_carte_joueur1()[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1()[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1()[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
        std::cout << "indicecarteivo" << std::endl;
        std::cout << indicecarteivo << std::endl;

    std::string textlourd= (joueur1->get_main())[indicecarteivo%joueur1->get_Nb_carte_main()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(250,280);
    window.draw(text);
    if (h==3){
    std::string textlourd= "Pas assez de point d'action !";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(230,455);
    window.draw(text);
    }
    else {
    std::string textlourd= "Voulez vous poser cette carte , appuyez sur espace pour confirmer";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(230,455);
    window.draw(text);
    

    }
    std::string pa=std::to_string(joueur1->get_point_action());
    sf::Text textpa(pa, font, 20);
    textpa.setColor(sf::Color(0,0,0));
    textpa.setPosition(100,535);
    window.draw(textpa);
    
    std::string pdv=std::to_string(joueur1->get_pointdevie());
    sf::Text textpdv(pdv, font, 20);
    textpdv.setColor(sf::Color(0,0,0));
    textpdv.setPosition(100,490);
    window.draw(textpdv);
    }


    else {
        if (GameState==4)
    {
          // GameState=3;
     //   std::cout << GameState <<std::endl;
      /*
        sf::Texture Terrain;
        ///std::cout << "Bogogoogogogo \n";
        window.clear();
        Terrain.loadFromFile("TerrainCarte.png");
        sf::Sprite spT(Terrain);
        window.draw(spT);
        sf::Texture pioche;
        pioche.loadFromFile("doscarte.png");
        sf::Sprite spritepioche(pioche);
        spritepioche.scale(sf::Vector2f(0.15f, 0.15f));
        spritepioche.setPosition(sf::Vector2f(675, 500)); 
        sf::Sprite spritepioche2(pioche);
        spritepioche2.scale(sf::Vector2f(0.15f, 0.15f));
        spritepioche2.setPosition(sf::Vector2f(185, 135)); 
        spritepioche2.setRotation(180);
        window.draw(spritepioche);
        window.draw(spritepioche2);
        int i;
        sf::Texture cartemain;
        cartemain.loadFromFile("evasioncarte.jpg");
        sf::Texture carteterrain;
        carteterrain.loadFromFile("evasion_invoque.png");

        for (i=0;i<joueur1->get_Nb_carte_main();i++){
        sf::Sprite cartetemp(cartemain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(454-i*70, 485));
        int rouge=(joueur1->get_main())[i].get_pts_atk();
        int bleu=(joueur1->get_main())[i].get_pdv();
        int vert=(joueur1->get_main())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
        for (i=0;i<unbeauterrain->get_carte_joueur1().size();i++){
        sf::Sprite cartetemp(carteterrain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(454-i*70,455));
        int rouge=unbeauterrain->get_carte_joueur1()[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1()[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1()[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
      GameState=3;

    std::string textlourd= "grosse merde;";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(250,250);
    window.draw(text);
*/


    }
     if (GameState == 2){
        window.close();
        }
    else monmenu.draw(window); 
}


    
    window.display();
}
