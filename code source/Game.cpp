#include "Game.hpp"
#include "Renderer.hpp"
/*
	Classe qui correspond à la machine du jeu

	*/

	//constructeurs /Destructeurs
	Game::Game(){
	}

	Game::Game(Renderer& renderer){
		this->initVariables(renderer);
	}

	Game::~Game(){  //Destructors
		//Environments
		for(auto *v : this->environments){
			delete v;
		}
		//Bonus
		//Remove vitesses
		for(auto *v : this->speeds){
			delete v;
		}
		//Remove healths
		for(auto *h : this->healths){
			delete h;
		}
		//Remove attacks
		for(auto *a : this->attacks){
			delete a;
		}
		//Armes
		//Remove lasers
		for(auto *l : this->lasers){
			delete l;
		}
		for(auto *l : this->guns){
			delete l;
		}
	}


//--------------fonctions publiques

void Game::initVariables(Renderer& render){

	this->window = &render.getWindow();    //récupère la fenêtre
	initEnvironment();   //initalise les objets de l'environnments (décor, bar de vie, maison ..etc)
	this->j1.initObject("robot1.png",25.f,250.f);   //initialise le joueur 1
	this->j2.initObject("robot2.png",1540.f,820.f); //initialise le joueur 2
	spawnArms();  //initialise les armes dans l'arène
	spawnBonus();  //initalise les bonus dans l'arène
	initFont();  //initialise le font pour le texte
	initAllText();  //initalise tous les textes
	this->oldtime = clock.getElapsedTime().asSeconds();  //initialise et sauvegarde la valeur du timer
}

void Game::initEnvironment(){  //initalise les objets de l'environments
	this->environments.push_back(new Environment("map.png",0.f,0.f));   //initalise le sprite pour le sol avec 'herbe verte
	this->environments.push_back(new Environment("score_bar.png",0.f,0.f)); //initalise la bar des scores
	this->environments.push_back(new Environment("maison.png",400.f,400.f)); // initalise les maisons
	this->environments.push_back(new Environment("maison.png",1000.f,600.f));
}

void Game::spawnArms(){  //fait apparaitre les armes au début du jeu
	//spawn lasers et gun
	for(int i=0; i<3; i++){   //crée 3 lasers et 3 guns sur la map
		this->lasers.push_back(new Laser());  //création et ajout dans une liste d'arme type laser
		this->guns.push_back(new Gun());  //création ajout dans une liste d'arme type gun
	}
}

void Game::spawnBonus(){  //fait apparaitre les bonus au début du jeu
	for(int i=0; i<4; i++){  //crée 4 bonus Health et 4 Bonus Speed et 4 Bonus Attack sur la map
		this->healths.push_back(new Health()); //création et ajout dans une liste
		this->speeds.push_back(new Speed());
		this->attacks.push_back(new Attack());
	}
}

void Game::respawnArme(){  //définis la réapparition des armes selon des temps de réapparition différents
	int time =  clock.getElapsedTime().asSeconds();  //récupère le timer
		if(static_cast<int>(time)%15 == 0){    //crée toutes les 15 secondes un gun
			this->guns.push_back(new Gun());
		}
		if(static_cast<int>(time)%30 == 0){   //crée toutes les 30 secondes un laser
			this->lasers.push_back(new Laser());
		}

}
void Game::respawnBonus(){ //définis la réapparition des bonus selon des temps de réapparition différents
	int time =  clock.getElapsedTime().asSeconds();
		if(static_cast<int>(time)%20 == 0){   //crée toutes les 20 secondes un bonus attack
			this->attacks.push_back(new Attack());
		}
		if(static_cast<int>(time)%40 == 0){  //crée toutes les 40 secondes un bonus de vie
			this->healths.push_back(new Health());
		}
		if(static_cast<int>(time)%30 == 0){  //crée toutes les 30 secondes un bonus de vitesse
			this->speeds.push_back(new Speed());
		}

}

//----------------Gestion du Texte -------
void Game::initFont(){   //initalition du font pour le texte
	if(!(this->font.loadFromFile("Dosis-Light.ttf"))){
		std::cout << "ERROR::Game::INITFONTS:: Failed to load fonts !" << "\n";
	}
}

void Game::initText(sf::Text& Texte , float x, float y){  //initalisation d'un texte
	Texte.setFont(this->font); //applique le font
	Texte.setCharacterSize(20); //définis la taille
	Texte.setFillColor(sf::Color::Black); //définis la couleur du texte
	Texte.setPosition(sf::Vector2f(x,y)); //définis la position du texte
	Texte.setString("NONE"); //définis le contenue du texte
}

void Game::initAllText(){  //initalisation de tous les textes
		initText(this->j1Text, 600, 20);   //affiche les stats du joueur ( point d'attaque, point de vitesse )
		initText(this->j2Text, 900, 20);
		initText(this->timer1, 730, 20); //affiche le timer
		initText(this->Arme1, 20, 70);  //affiche les munitions sur les armes
		initText(this->Arme2, 1200, 70);
		initText(this->Pv1, 120, 25);  //affiche les points de vies du joueur
		initText(this->Pv2, 1350, 25);
}


void Game::updateText(){   //met à jour les textes

	std::stringstream ss1, ss2, stemps, arme1, arme2, pv1, pv2, gameover;
	int temps = clock.getElapsedTime().asSeconds();
	ss1 << "J1:\n" << "Speed: " << this->j1.getSpeed() <<   "\n" << "Health: " <<this->j1.getHp() <<  "/" << this->j1.getMaxhp() << "\n" << "Attack: " << this->j1.getAttack() <<   "\n";

	ss2 << "J2:\n" << "Speed: " << this->j2.getSpeed() <<  "\n" << "Health: " <<this->j2.getHp() <<  "/" << this->j2.getMaxhp() << "\n" << "Attack: " << this->j2.getAttack() <<   "\n";
	stemps << "TIMER " << temps << "\n";
	arme1 << "J1:\n" << "Gun_ammo: " << this->j1.getGun() <<  "\n" << "Laser_ammo: " <<this->j1.getLaser() <<  "\n" ;
	arme2 << "J2:\n" << "Gun_ammo: " << this->j2.getGun() <<  "\n" << "Laser_ammo: " <<this->j2.getLaser() <<  "\n" ;
	pv1 << "J1-> PV:" << this->j1.getHp() <<  "\n" ;
	pv2 << "J2-> PV:" << this->j2.getHp() <<  "\n" ;
	this->j1Text.setString(ss1.str());    //applique le contenue du texte
	this->j2Text.setString(ss2.str());
	this->Arme1.setString(arme1.str());
	this->Arme2.setString(arme2.str());
	this->timer1.setString(stemps.str());
	this->Pv1.setString(pv1.str());
	this->Pv2.setString(pv2.str());

}


//mis à jour de la position et de l'existance des projectiles
void Game::updateProjectile(Player& j, Player& j2){  // (player j =  joueur qui tire le projectile ,   joueur j2 : ennemi qui peut se prendre le projectile  )
	std::vector<Projectile*>& proj = j.getProjectile();  //on récupère la liste de projectiles du joueur qui tire
	for(size_t i=0; i< proj.size();i++){  //on parcours la liste de ses projectiles
		proj[i]->setMove(j);   //on fait bouger les projectiles du joueur qui a tiré
			if(colisionProjectile(*proj[i]))  //si le projectile touche le décor (maison ou bord de l'écran)-> supprimé
				j.deleteProjectile(i);
			if(colisionProjectilePlayer(*proj[i], j2)){  //si le projectile touche le joueur ennemi -> dégats sur j2 + supprime le projectile
				j.deleteProjectile(i);
				j2.setHp(j2.getHp()-j.getAttack()*2); //dégats sur le joueur 2 proportionnelle au point d'attaque du joueur 1
				if(j2.getHp() <= 0 ){  //si un joueur va subir des dégats qui vont mettre ses points de vie en négatif ->  Hp = 0
					j2.setHp(0);
				}
			}
	}
}
//test la fin du jeu
int Game::TestGameState(){  // Test si un joueur n'a plus de vie :  Hp = 0
	if(j1.getHp() <= 0 || j2.getHp() <=0){  //si un joueur n'a plus de vie
		sf::Text gameovers;    //on affiche le message de gameover
		gameovers.setFont(this->font);   //création du message du gameover avec le font
		gameovers.setCharacterSize(90);
		gameovers.setFillColor(sf::Color::Red);
		gameovers.setPosition(sf::Vector2f(300,400)); //position du message
		if(j1.getHp() <= 0){
			gameovers.setString("GAME OVER : PLAYER 2 WIN!");   //si le joueur 1 a 0 HP  , joueur 2 gagne
		}
		else{
			gameovers.setString("GAME OVER : PLAYER 1 WIN!");  //si le joueur 2 a 0 HP  , joueur 1 gagne
		}
		this->window->draw(gameovers);  //on dessine le texte
		this->window->display();  //on affiche le texte
		return 0;
	}
	return 1;
}

//vérifie si fenêtre est ouverte
const bool Game::running() const{
	return this->window->isOpen();
}


int Game::colisionEnvironment(Player player){   //Test la colision d'un joueur avec tous les obstacles de l'environnment
	for(int i = 1; i < environments.size() ; i++ ){  //commence la boucle à 1, car l'objet environnmeent 0 correspond au sol avec l'herbe
		if(player.getSpriteBounds().intersects(environments[i]->getSpriteBounds())) //test colision (vérifie si les sprites sont en intersection )
			return 1;
		else if(player.getPosx()<25 || player.getPosx()>1560 || player.getPosy()>860 )  //colision avec les bords de la fenêtre
			return 1;
	}
	return 0;
}

template<typename b>
void Game::colisionBonus(Player& player, std::vector<b*>& bonus){   //Test la colision entre 1 joueur et n'importe qu'elle type d'objet collectable (bonus ou arme)
	for(int i=0; i<bonus.size(); i++){  //parcours la listes de l'objet collectable (bonus ou arme)
		//test la colision entre le joueur et tout les objets de cette listes
		if(player.getSpriteBounds().intersects(bonus[i]->getSpriteBounds())){
			bonus.erase(bonus.begin() + i);  //efface l'objet collectable (bonus ou arme )
			bonus[i]->gainStat(player);  //applique la fonction "gainstat " qui donne un attributs (bonus ou munitions) au joueur en fonction du type d'objet rammassé
		}
}
}

int Game::colisionProjectile(Projectile& p){   //Test la colision d'un  projectile avec tous les obstacles de l'environnment
	for(int i = 1; i < environments.size() ; i++ ){  //commence la boucle à 1, car l'objet environnmeent 0 correspond au fond avec de l'herbe
		if(p.getSpriteBounds().intersects(environments[i]->getSpriteBounds())) //test colision du projectile avec le décor
			return 1;
		else if(p.getPosx()<0 || p.getPosx()>1600 || p.getPosy()>900 || p.getPosy() <150 )  //test la colision avec les bords de la fenêtre
			return 1;
	}
	return 0;
}

int Game::colisionProjectilePlayer(Projectile& p, Player& j){   //Test la colision entre un projectile et un joueur ennemi
		if(p.getSpriteBounds().intersects(j.getSpriteBounds())) //test colision
			return 1;
	return 0;
}

void Game::colectAllObject(Player& j1){  //vérifie la collecte de tous les objets collectables pour un joueur
	colisionBonus(j1, attacks);
	colisionBonus(j1, healths);
	colisionBonus(j1, speeds);
	colisionBonus(j1, guns);
	colisionBonus(j1, lasers);
}

void Game::exit(){  //permet de fermée la fenêtre du jeu en appuyant sur échape
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			window->close();
	}
}
//mise à jour des elements de la fenêtre
void Game::update(){
		if(TestGameState()){ //si aucun joueur n'a 0 HP

			float speed1 = j1.getSpeed();  //récupère la variable de vitesse du joueur 1
			float speed2 = j2.getSpeed();

			int time = clock.getElapsedTime().asSeconds();   //permet la réapparition des bonus et armes
			if( time > oldtime){  //on vérifie si le temps en seconde à changer
				respawnArme();
				respawnBonus();  //réapparition armes et bonus
				oldtime = clock.getElapsedTime().asSeconds();  //on sauvegarde l'ancien temps du timer (permet de vérifié si le temps à changer )
			}
			//Update
	  //j1
				float backP1x = j1.getPosx();  //récupère la position du joueur 1 en x
				float backP1y = j1.getPosy();  //récupère la position du joueur 1 en y
	//déplacement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){  //GAUCHE
					j1.setMove(-speed1, 0.f);
					j1.setDir(1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){  //DROITE
					j1.setMove(speed1, 0.f);
					j1.setDir(2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){ //HAUT
					j1.setMove(0.f, -speed1);
					j1.setDir(3);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ //BAS
					j1.setMove(0.f, speed1);
					j1.setDir(4);
				}
				if(shoottimer1 < 7) shoottimer1++;   //tire de projectile   (shoottimer1 = un délai entre 2 tirs)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && shoottimer1>=7 && j1.getGun()>0){ //tire si assez de munition
					j1.addProjectile();  //création d'un projectile dans la liste de projectiles du joueur 1
					shoottimer1 = 0;   //reset du délai de tir
					j1.setGun(j1.getGun()-1);  // diminution de 1 munition
				}
				//test colision
				if(colisionEnvironment(j1))  //Si il y a colision avec l'environments dans ça futur position
					j1.setPos(backP1x,backP1y); //on le fait revenir à sa position initial (avant d'avoir tenter le déplacement)
				colectAllObject(j1); //test la collecte les objets pour le joueur 1
				updateProjectile(j1,j2); //met à jour les projectiles du joueur 1
	//j2
				float backP2x = j2.getPosx();
				float backP2y = j2.getPosy();
	//déplacement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){   //GAUCHE
					j2.setMove(-speed2, 0.f);
					j2.setDir(1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){  //DROITE
					j2.setMove(speed2, 0.f);
					j2.setDir(2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){  //HAUT
					j2.setMove(0.f, -speed2);
					j2.setDir(3);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){  //BAS
					j2.setMove(0.f, speed2);
					j2.setDir(4);
				}
				if(shoottimer2 < 7) shoottimer2++;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && shoottimer2>=7 && j2.getGun()>0){
					j2.addProjectile();
					shoottimer2 = 0;
					j2.setGun(j2.getGun()-1);
				}
	//test colision
				if(colisionEnvironment(j2))
					j2.setPos(backP2x,backP2y);
				colectAllObject(j2);
				updateProjectile(j2,j1);
				updateText();
	}

}

//----------------AFFICHAGE


void Game::display(Renderer& renderer){

	this->window->clear();//nettoie le contenu de la frame précedente
	for( auto *e : environments ){e->display(renderer);} //affiche le décor / obstacle / environnment
	this->j1.display(renderer);//affiche le personnage
	this->j2.display(renderer);//affiche le personnage
	//affiche les armes
	for(auto *l : this->lasers){l->display(renderer);}
	for(auto *l : this->guns){l->display(renderer);}
	//affiche les bonus
	for(auto *h : this->healths){h->display(renderer);}
	for(auto *s : this->speeds){s->display(renderer);}
	for(auto *a : this->attacks){a->display(renderer);}
	//affiche les projectiles du joueur 1 et 2
	for(auto *l : j1.getProjectile()){l->display(renderer);}
	for(auto *k : j2.getProjectile()){k->display(renderer);}
	//affichage du texte
	this->window->draw(this->j1Text);
	this->window->draw(this->j2Text);
	this->window->draw(this->timer1);
	this->window->draw(this->Arme1);
	this->window->draw(this->Arme2);
	this->window->draw(this->Pv1);
	this->window->draw(this->Pv2);

	this->window->display();//affichage de tous les objets

}
