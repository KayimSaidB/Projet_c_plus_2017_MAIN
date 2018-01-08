#include "Game.hh"
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <SFML/Audio.hpp>
#include <thread>
#include <chrono>
Menu monmenu(WIDTH, HEIGHT);

int GameState =0;
int h=4;
int indicecarteivo;
int indicecarteattaquant=0;
int indicecarteattaque=0;
bool whoseturn=true;
int countturn=0;
Game::Game() : window(sf::VideoMode(WIDTH,HEIGHT),"Welcome To Paradise Papers !")
{
    window.setFramerateLimit(60);

}

void Game::run()

{   
  Joueur untypebien(50,700,"Mohamed",1);
  Joueur unsecondtypebien(50,700,"Harold",2);
  Terrain unbeauterrain(0,0); 
 sf::Music music;
music.openFromFile("musique.ogg");

music.play();
music.setLoop(true);
music.setVolume(50);
//music.setPitch(1.1);
    untypebien.init_deck();
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
   unsecondtypebien.init_deck();

    while (window.isOpen())
    {   
        if (whoseturn==true){
        processEvents(&unsecondtypebien,&untypebien,&unbeauterrain);
        update(&unsecondtypebien,&untypebien,&unbeauterrain);
        render(&unsecondtypebien,&untypebien,&unbeauterrain);
    }
    else {

        processEvents(&untypebien,&unsecondtypebien,&unbeauterrain);
        update(&untypebien,&unsecondtypebien,&unbeauterrain);
        render(&untypebien,&unsecondtypebien,&unbeauterrain);
    }
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

                        break;
                    case sf::Keyboard::Left:
                        indicecarteivo=(indicecarteivo-1+joueur1->get_Nb_carte_main())%joueur1->get_Nb_carte_main();
                                            
                        break;
                    
                    case sf::Keyboard::P:
                    whoseturn=not whoseturn;
                    joueur1->init_pa();
                    unbeauterrain->attack_reinit(joueur1->get_num());
                     joueur2->pioche_une_carte();
                     countturn++;
                    break;

                    case sf::Keyboard::B:
                    GameState=5;
                    break;
                    }
             }
    if (GameState==5){
                switch (event.key.code){
                    case sf::Keyboard::A:
                        GameState=6; //attaqué
                        break;

                    case sf::Keyboard::Right:
                        indicecarteattaquant=indicecarteattaquant+1;
                        break;
                    case sf::Keyboard::Left:
                        indicecarteattaquant=indicecarteattaquant-1;

                        break;

                    
                    }
             }
     if (GameState==6){
                switch (event.key.code){
                    case sf::Keyboard::C:
                        GameState=7; //attaqué
                        break;

                    case sf::Keyboard::Right:
                        indicecarteattaque=indicecarteattaque+1;
                        break;
                    case sf::Keyboard::Left:
                        indicecarteattaque=indicecarteattaque-1;

                        break;
                    case sf::Keyboard::D:
                        GameState=8;
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



 if (joueur1->choisir_carte_dans_main_et_poser(unbeauterrain,indicecarteivo)==false){

            GameState=3;
            h=3;
        }
        else {h=8;}

GameState=3;

}
if (GameState==7){
    GameState=3;
if (unbeauterrain->attack_enclenche(indicecarteattaquant,indicecarteattaque,joueur1->get_num())==false){
    h=4;
}

}
if (GameState==8){
     GameState=3;

if (unbeauterrain->already_attack_fun(joueur1->get_num(),indicecarteattaque)==false){
        joueur2->set_pdv(joueur2->get_pointdevie()-unbeauterrain->get_carte_joueur1(joueur1->get_num())[indicecarteattaque].get_pts_atk());

        unbeauterrain->set_already_attack( joueur1->get_num(),indicecarteattaque);
    
    }
else {
    h=4;

}

}

}

void Game::render(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{   
    sf::Font font;
    font.loadFromFile("belwe.ttf");
    window.clear();
    if (GameState == 1 || GameState ==3 || GameState==5 || GameState==6){
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
        for (i=0;i<joueur2->get_Nb_carte_main();i++){
        sf::Sprite cartetemp(pioche);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(524-i*70, 125));
        cartetemp.setRotation(180);
        window.draw(cartetemp);
        }

      for (i=0;i<unbeauterrain->get_carte_joueur1(joueur1->get_num()).size();i++){
        sf::Sprite cartetemp(carteterrain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(450-i*100,305));
        int rouge=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
          for (i=0;i<unbeauterrain->get_carte_joueur1(joueur2->get_num()).size();i++){
        sf::Sprite cartetemp(carteterrain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(450-i*100,175));
        int rouge=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        //cartetemp.setRotation(180);
        window.draw(cartetemp);
        }
    if (GameState==3 || GameState==1){
            GameState=3;
     std::string textlourd= (joueur1->get_main())[indicecarteivo%joueur1->get_Nb_carte_main()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(250,280);
    window.draw(text);
    sf::Texture curseur;
    curseur.loadFromFile("79532.jpg");
    sf::Sprite spritecurseur(curseur);
    spritecurseur.scale(sf::Vector2f(0.15f, 0.15f));
  	spritecurseur.setPosition(sf::Vector2f(450-indicecarteivo*100,485));
    if (h==3){
    std::string textlourd= "Pas assez de point d'action ! N'avez vous donc pas honte ?";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(230,455);
    window.draw(text);
    }
    if (h==4){
    std::string textlourd= "Votre Monstre a déja attaque, cessez cette gourmandise";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(230,455);
    window.draw(text);


    }
    else {
    std::string textlourd= "Voulez vous poser cette carte , appuyez sur espace pour confirmer\n\npasser  a la phase attaque avec B, passer son tour avec P";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(230,455);
    window.draw(text);
    

    }
}
if ((GameState==5) && countturn>0){

    std::string textlourd= unbeauterrain->get_carte_joueur1(joueur1->get_num())[indicecarteattaquant%unbeauterrain->get_carte_joueur1(joueur1->get_num()).size()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(250,280);
    window.draw(text);
    std::string textlourd2= "Voulez vous attaquer avec cette carte, appuyez A pour confirmer";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color(0,0,0));
    text2.setPosition(230,455);
    window.draw(text2);

}
if (GameState==6 && unbeauterrain->get_carte_joueur1(joueur2->get_num()).size() >0){
    std::string textlourd= unbeauterrain->get_carte_joueur1(joueur2->get_num())[indicecarteattaque%unbeauterrain->get_carte_joueur1(joueur2->get_num()).size()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(250,280);
    window.draw(text);
    std::string textlourd2= "Voulez vous attaquer cette carte, appuyez C pour confirmer, D pour une attaque directe";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color(0,0,0));
    text2.setPosition(230,455);
    window.draw(text2);

}
  if ((GameState==6) && (unbeauterrain->get_carte_joueur1(joueur2->get_num()).size()==0)){

  	GameState=8;
  }
  if((GameState==5) && countturn==0){
  	
  	std::string textlourd2= "On attaque pas dès le premier tour voyons !";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color(0,0,0));
    text2.setPosition(230,455);
    window.draw(text2);
     std::this_thread::sleep_for(std::chrono::seconds(1)); 

    GameState=3;
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

     std::string pa2=std::to_string(joueur2->get_point_action());
    sf::Text textpa2(pa2, font, 20);
    textpa2.setColor(sf::Color(0,0,0));
    textpa2.setPosition(715,100);
    window.draw(textpa2);
    
    std::string pdv2=std::to_string(joueur2->get_pointdevie());
    sf::Text textpdv2(pdv2, font, 20);
    textpdv2.setColor(sf::Color(0,0,0));
    textpdv2.setPosition(715,55);
    window.draw(textpdv2);

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
