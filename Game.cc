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
int indiceperdant;
CarteSpeciale spetypebien=CarteSpeciale("Charité divine",50, "Vous rend 500 Point de vie",1,1);
CarteSpeciale spesecondtypebien=CarteSpeciale("Destruction demoniaque",50,"Detruit toutes les cartes de l'adversaire",3,2);
Game::Game() : window(sf::VideoMode(1200,812),"Welcome To Paradise Papers !")
{
    window.setFramerateLimit(100);

}

void Game::run()

{   
  Joueur untypebien(50,500,"Mohamed",1);
  Joueur unsecondtypebien(50,500,"Harold",2);
  Terrain unbeauterrain(0,0); 
  unbeauterrain.attack_reinit(1);
  unbeauterrain.attack_reinit(2);

 sf::Music music,music2;
music.openFromFile("musique.ogg");
music2.openFromFile("tkt2.ogg");
music.play();
music.setLoop(true);
music.setVolume(50);
//music.setPitch(1.1);
    untypebien.init_deck();
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
   unsecondtypebien.init_deck();

    while (window.isOpen())
    {   if (untypebien.get_pointdevie()<=0){
        std::cout << untypebien.get_pointdevie() << std::endl;
        GameState=9;
        indiceperdant=2;
        std::cout << "on fout quoi wesh"<<std::endl;

         music.stop();
         
    }
        if (unsecondtypebien.get_pointdevie()<=0) {
            GameState=9;
            indiceperdant=1;
            std::cout << "on fout quoi "<<std::endl;
            music.stop();
        
        }
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
                   unbeauterrain->attack_reinit(joueur2->get_num());

                     if (joueur2->get_Nb_carte_main()<5)joueur2->pioche_une_carte();
                     countturn++;
                    break;

                    case sf::Keyboard::B:
                    GameState=5;
                    break;
                    case sf::Keyboard::S:
                    //spetypebien.effet_special(3,joueur1,joueur2,unbeauterrain);
                    GameState=10;
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
    if (GameState==10){
            switch (event.key.code){
                    case sf::Keyboard::C:
                        GameState=11; 
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
            {    


                GameState=4;}
        }

      
}


void Game::update(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{ 
    if (GameState == 1 && h==4){
    int c;
    for (c=0;c<3;c++){
    joueur1->pioche_une_carte();
    joueur2->pioche_une_carte();
}
    joueur1->pioche_une_carte(); // une carte de plus pour le joueur 1
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

if (unbeauterrain->already_attack_fun(joueur1->get_num(),indicecarteattaquant)==false){
        joueur2->set_pdv(joueur2->get_pointdevie()-unbeauterrain->get_carte_joueur1(joueur1->get_num())[indicecarteattaquant].get_pts_atk());

        unbeauterrain->set_already_attack( joueur1->get_num(),indicecarteattaquant);
    
    }
else {
    h=4;

}

}

if (GameState==11){
    GameState=3;
    bool marche;
    if (joueur1->get_num()==1)  marche=spetypebien.effet_special(spetypebien.get_indice_effet(),joueur1,joueur2,unbeauterrain);
    else  marche=spesecondtypebien.effet_special(spesecondtypebien.get_indice_effet(),joueur1,joueur2,unbeauterrain);
if (marche==false) h=3;
  
}

}
void Game::afficher_Victoire(int indice){
        sf::Font font;
        font.loadFromFile("belwe.ttf");
        sf::Texture Victoire;
        window.clear();
        Victoire.loadFromFile("yugitkt.png");
        sf::Sprite spriteV(Victoire);
        window.draw(spriteV);
        std::string textlourd= "Victoire du joueur" + std::to_string(indice);
        sf::Text text(textlourd, font, 54);
        text.setColor(sf::Color(0,0,0));
        text.setPosition(200,300);
        window.draw(text);


}
void Game::afficher_cara_joueur(Joueur *joueur1,Joueur *joueur2){
    sf::Font font;
    font.loadFromFile("belwe.ttf");
    std::string pa=joueur1->affichage();
    sf::Text textpa(pa, font, 14);
    textpa.setColor(sf::Color(0,0,0));
    textpa.setPosition(134,696);
    window.draw(textpa);
     std::string pa2=joueur2->affichage();
    sf::Text textpa2(pa2, font, 14);
    textpa2.setColor(sf::Color(0,0,0));
    textpa2.setPosition(128,68);
    window.draw(textpa2);
   


}
void Game::afficher_terrain_vide(Joueur *joueur1,Joueur *joueur2){
     
        sf::Texture Terrain;
        window.clear();
        Terrain.loadFromFile("plage2.png");
        sf::Sprite spT(Terrain);
        window.draw(spT);
        afficher_cara_joueur(joueur1,joueur2);
   
        
}
void Game::afficher_carte_main(Joueur *joueur1,Joueur *joueur2){   
    ///sert à afficher les mains de chaque joueur selon leur perspective
        int i;
        sf::Texture cartemain;
        cartemain.loadFromFile("cartejouee.png");

        for (i=0;i<joueur1->get_Nb_carte_main();i++){
        sf::Sprite cartetemp(cartemain);
        cartetemp.setPosition(sf::Vector2f(410+i*75, 675));
        int rouge=(joueur1->get_main())[i].get_pts_atk();
        int bleu=(joueur1->get_main())[i].get_pdv();
        int vert=(joueur1->get_main())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }
     
    }
    void Game::afficher_terrain_rempli(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain){
     sf::Texture carteterrain;
     sf::Texture carteterrain2;
    carteterrain.loadFromFile("carteposee.png");
    carteterrain2.loadFromFile("carteposeeface.png");

    int i;
    sf::Texture swordT;
    swordT.loadFromFile("sword.png");
 for (i=0;i<unbeauterrain->get_carte_joueur1(joueur1->get_num()).size();i++){
        sf::Sprite cartetemp(carteterrain);
        cartetemp.scale(sf::Vector2f(0.15f, 0.15f));
        cartetemp.setPosition(sf::Vector2f(413+i*100,534));
        int rouge=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1(joueur1->get_num())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
       window.draw(cartetemp);
    if(unbeauterrain->already_attack_fun(joueur1->get_num(),i)==true){
            sf::Sprite sword(swordT);
            sword.scale(sf::Vector2f(0.05f, 0.05f));
            sword.setPosition(sf::Vector2f(460+i*100,530));
            window.draw(sword);

      }
        
        }
          for (i=0;i<unbeauterrain->get_carte_joueur1(joueur2->get_num()).size();i++){
        sf::Sprite cartetemp(carteterrain2);
        cartetemp.setPosition(sf::Vector2f(425+i*75,170));
        int rouge=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_pts_atk();
        int bleu=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_pdv();
        int vert=unbeauterrain->get_carte_joueur1(joueur2->get_num())[i].get_point_action();
        cartetemp.setColor(sf::Color(rouge%255,bleu%255,vert%255));
        window.draw(cartetemp);
        }




    }

void Game::main_phase(Joueur* joueur1){
    sf::Font font;
    font.loadFromFile("belwe.ttf");
    std::string textlourd= (joueur1->get_main())[indicecarteivo%joueur1->get_Nb_carte_main()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(415,439);
    window.draw(text);
    sf::Texture curseur;
    curseur.loadFromFile("cursor.png");
    sf::Sprite spritecurseur(curseur);;
    spritecurseur.setPosition(sf::Vector2f(452+indicecarteivo%joueur1->get_Nb_carte_main()*80,733));
    window.draw(spritecurseur);
    if (h==3){ /// pas assez de point d'action pour poser
    std::string textlourd= "Pas assez de point d'action !\n\n N'avez vous donc pas honte ?";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color::White);
    text.setPosition(890,63);
    window.draw(text);
    }
    else {if (h==4){ /// Cherche à attaquer alors que ca déjà été effectué
    std::string textlourd= "Votre Monstre a deja attaque,\n\n cessez cette gourmandise";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color::White);
    text.setPosition(890,63);
    window.draw(text);
h=8;
}
  
    else {
    std::string textlourd= "Voulez vous poser cette carte ,\n\n appuyez sur espace pour confirmer\n\n passer  a la phase attaque avec B,\n\n passer son tour avec P";
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color::White);
    text.setPosition(890,63);
    window.draw(text);

    

    }
}
}
void Game::choix_attaquant(Joueur *joueur1,Terrain *unbeauterrain){
     sf::Font font;
    font.loadFromFile("belwe.ttf");
    std::string textlourd= unbeauterrain->get_carte_joueur1(joueur1->get_num())[indicecarteattaquant%unbeauterrain->get_carte_joueur1(joueur1->get_num()).size()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(415,439);
    window.draw(text);
    std::string textlourd2= "Voulez vous attaquer avec cette carte,\n\n appuyez A pour confirmer";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color::White);
    text2.setPosition(890,63);
    window.draw(text2);
    sf::Texture curseur;
    curseur.loadFromFile("cursor.png");
    sf::Sprite spritecurseur(curseur);
    spritecurseur.setPosition(sf::Vector2f(450+indicecarteattaquant%unbeauterrain->get_carte_joueur1(joueur1->get_num()).size()*100,570));
    window.draw(spritecurseur);

}
void Game::choix_attaque(Joueur *joueur2,Terrain *unbeauterrain){
     sf::Font font;
    font.loadFromFile("belwe.ttf");
     std::string textlourd= unbeauterrain->get_carte_joueur1(joueur2->get_num())[indicecarteattaque%unbeauterrain->get_carte_joueur1(joueur2->get_num()).size()].affichage();
    sf::Text text(textlourd, font, 13);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(474,280);
    window.draw(text);
    std::string textlourd2= "Voulez vous attaquer cette carte,\n\n appuyez C pour confirmer,\n\n D pour une attaque directe";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color::White);
    text2.setPosition(890,63);
    window.draw(text2);
    sf::Texture curseur;
    curseur.loadFromFile("cursor.png");
    sf::Sprite spritecurseur(curseur);
    spritecurseur.setPosition(sf::Vector2f(474+indicecarteattaque%unbeauterrain->get_carte_joueur1(joueur2->get_num()).size()*75,216));
    window.draw(spritecurseur);
}
void Game::render(Joueur *joueur1,Joueur *joueur2,Terrain *unbeauterrain)
{   
    
    window.clear();
    int i;
    sf::Font font;
    font.loadFromFile("belwe.ttf");
    if (GameState == 1 || GameState ==3 || GameState==5 || GameState==6 || GameState==10){
        afficher_terrain_vide(joueur1,joueur2);
        afficher_carte_main(joueur1,joueur2);
        afficher_terrain_rempli(joueur1,joueur2,unbeauterrain);
    if (GameState==3 || GameState==1){
        GameState=3;
        main_phase(joueur1);
}
if ((GameState==5) && countturn>0){
   choix_attaquant(joueur1,unbeauterrain);
}
if (GameState==10){
    std::string textlourd2;
    if (joueur1->get_num()==1) textlourd2 = spetypebien.affichage();
    else textlourd2=spesecondtypebien.affichage();
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color(0,0,0));
    text2.setPosition(250,280);
    window.draw(text2);
    std::string textlourd3="Espace pour Revenir,\n\n C pour poser la carte";
    sf::Text text3(textlourd3, font, 13);
    text3.setColor(sf::Color::White);
    text3.setPosition(890,63);
    window.draw(text3);


}
if (GameState==6 && unbeauterrain->get_carte_joueur1(joueur2->get_num()).size() >0){
   choix_attaque(joueur2,unbeauterrain);
}
  if ((GameState==6) && (unbeauterrain->get_carte_joueur1(joueur2->get_num()).size()==0)){

  	GameState=8;
  }
  if((GameState==5) && countturn==0){
  	
  	std::string textlourd2= "On attaque pas des le premier tour voyons !\n\n";
    sf::Text text2(textlourd2, font, 13);
    text2.setColor(sf::Color::White);
    text2.setPosition(890,63);
    window.draw(text2);
   GameState=3;
  }
    }
  else {
        
     if (GameState == 2){
        window.close();
        
        }
    if (GameState==9){
        afficher_Victoire(indiceperdant);

    }
    else monmenu.draw(window); 
}


    
    window.display();
}
