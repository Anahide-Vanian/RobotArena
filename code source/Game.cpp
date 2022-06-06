#include "Game.hpp"
#include "Renderer.hpp"
/*
	Classe qui correspond à la machine du jeu

	*/

//-------------fonctions privées

void Game::initVariables(Renderer& render){

	this->window = &render.getWindow();
	initEnvironment();
	this->j1.initObject("robot1.png",25.f,250.f);
	this->j2.initObject("robot2.png",1540.f,820.f);
	spawnArms();
	spawnBonus();
	initFont();
	initAllText();
	this->oldtime = clock.getElapsedTime().asSeconds();

	this->nbBoxesCollected=0;

}

void Game::initEnvironment(){
	this->environments.push_back(new Environment("map.png",0.f,0.f));
	this->environments.push_back(new Environment("score_bar.png",0.f,0.f));
	this->environments.push_back(new Environment("maison.png",400.f,400.f));
	this->environments.push_back(new Environment("maison.png",1000.f,600.f));
}

void Game::spawnArms(){
	//sprawn lasers
	for(int i=0; i<3; i++){
		this->lasers.push_back(new Laser());
		this->guns.push_back(new Gun());
	}
}

void Game::spawnBonus(){
	for(int i=0; i<4; i++){
		this->healths.push_back(new Health());
		this->speeds.push_back(new Speed());
		this->attacks.push_back(new Attack());
	}
}

void Game::respawnArme(){
	int time =  clock.getElapsedTime().asSeconds();
		if(static_cast<int>(time)%15 == 0){
			this->guns.push_back(new Gun());
		}
		if(static_cast<int>(time)%30 == 0){
			this->lasers.push_back(new Laser());
		}

}
void Game::respawnBonus(){
	int time =  clock.getElapsedTime().asSeconds();
		if(static_cast<int>(time)%20 == 0){
			this->attacks.push_back(new Attack());
		}
		if(static_cast<int>(time)%40 == 0){
			this->healths.push_back(new Health());
		}
		if(static_cast<int>(time)%30 == 0){
			this->speeds.push_back(new Speed());
		}

}
void Game::initFont(){
	if(!(this->font.loadFromFile("Dosis-Light.ttf"))){
		std::cout << "ERROR::Game::INITFONTS:: Failed to load fonts !" << "\n";
	}
}

void Game::initText(sf::Text& Texte , float x, float y){
	Texte.setFont(this->font);
	Texte.setCharacterSize(20);
	Texte.setFillColor(sf::Color::Black);
	Texte.setPosition(sf::Vector2f(x,y));
	Texte.setString("NONE");
}

void Game::initAllText(){
		initText(this->j1Text, 600, 20);
		initText(this->j2Text, 900, 20);
		initText(this->timer1, 730, 20);
		initText(this->Arme1, 20, 70);
		initText(this->Arme2, 1200, 70);
}


void Game::updateText(){

	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream stemps;
	std::stringstream arme1;
	std::stringstream arme2;
	int temps = clock.getElapsedTime().asSeconds();
	ss1 << "J1:\n" << "Speed: " << this->j1.getSpeed() <<   "\n" << "Health: " <<this->j1.getHp() <<  "/" << this->j1.getMaxhp() << "\n" << "Attack: " << this->j1.getAttack() <<   "\n";

	ss2 << "J2:\n" << "Speed: " << this->j2.getSpeed() <<  "\n" << "Health: " <<this->j2.getHp() <<  "/" << this->j2.getMaxhp() << "\n" << "Attack: " << this->j2.getAttack() <<   "\n";
	stemps << "TIMER " << temps << "\n";
	arme1 << "J1:\n" << "Gun_ammo: " << this->j1.getGun() <<  " " << "Laser_ammo: " <<this->j1.getLaser() <<  "/" ;
	arme2 << "J2:\n" << "Gun_ammo: " << this->j2.getGun() <<  " " << "Laser_ammo: " <<this->j2.getLaser() <<  "/" ;
	this->j1Text.setString(ss1.str());
	this->j2Text.setString(ss2.str());
	this->Arme1.setString(arme1.str());
	this->Arme2.setString(arme2.str());
	this->timer1.setString(stemps.str());

}

int Game::colisionProjectile(Projectile& p){   //Test la colision d'un joueur avec tous les obstacles de l'environnment
	for(int i = 1; i < environments.size() ; i++ ){  //commence la boucle à 1, car l'objet environnmeent 0 correspond au fond avec de l'herbe
		if(p.getSpriteBounds().intersects(environments[i]->getSpriteBounds())) //test colision
			return 1;
		else if(p.getPosx()<0 || p.getPosx()>1600 || p.getPosy()>900 || p.getPosy() <150 )
			return 1;
	}
	return 0;
}

int Game::colisionProjectilePlayer(Projectile& p, Player& j){   //Test la colision d'un joueur avec tous les obstacles de l'environnment
		if(p.getSpriteBounds().intersects(j.getSpriteBounds())) //test colision
			return 1;
	return 0;
}

void Game::updateProjectile(Player& j, Player& j2){
	std::vector<Projectile*>& proj = j.getProjectile();
	for(size_t i=0; i< proj.size();i++){
		proj[i]->setMove(j);
			if(colisionProjectile(*proj[i]))
				j.deleteProjectile(i);
			if(colisionProjectilePlayer(*proj[i], j2)){
				j.deleteProjectile(i);
				j2.setHp(j2.getHp()-j.getAttack()*2);
			}
	}
}



//--------------fonctions publiques

//accesseurs

//vérifie si fenêtre est ouverte
const bool Game::running() const{
	return this->window->isOpen();
}



//constructeurs /Destructeurs
Game::Game(){
	//this->initVariables();
	//this->initWindow();
	//this->initFonts();
	//this->initText();

}
Game::Game(Renderer& renderer){
	this->initVariables(renderer);
}

Game::~Game(){
	delete this->window;
}

//---------------------POLLING EVENTS

int Game::colisionEnvironment(Player player){   //Test la colision d'un joueur avec tous les obstacles de l'environnment
	for(int i = 1; i < environments.size() ; i++ ){  //commence la boucle à 1, car l'objet environnmeent 0 correspond au fond avec de l'herbe
		if(player.getSpriteBounds().intersects(environments[i]->getSpriteBounds())) //test colision
			return 1;
		else if(player.getPosx()<25 || player.getPosx()>1560 || player.getPosy()>860 )
			return 1;
	}
	return 0;
}



template<typename b>
void Game::colisionBonus(Player& player, std::vector<b*>& bonus){
	for(int i=0; i<bonus.size(); i++){
		//player1 movement
		if(player.getSpriteBounds().intersects(bonus[i]->getSpriteBounds())){
			bonus.erase(bonus.begin() + i);
			bonus[i]->gainStat(player);
		}
}
}

void Game::colectAllObject(Player& j1){
	colisionBonus(j1, attacks);
	colisionBonus(j1, healths);
	colisionBonus(j1, speeds);
	colisionBonus(j1, guns);
	colisionBonus(j1, lasers);
}

//modification des attributs du personnage en fonction des clés pressés
//----------------MISE A JOUR
//mise à jour du texte
void Game::exit(){
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

		float speed1 = j1.getSpeed();
		float speed2 = j2.getSpeed();
		float speed = 8;

		int time = clock.getElapsedTime().asSeconds();
		if( time > oldtime){
			respawnArme();
			respawnBonus();
			oldtime = clock.getElapsedTime().asSeconds();
		}
		//Update
//j1
			float backP1x = j1.getPosx();
			float backP1y = j1.getPosy();
//déplacement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
				j1.setMove(-speed1, 0.f);
				j1.setDir(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				j1.setMove(speed1, 0.f);
				j1.setDir(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
				j1.setMove(0.f, -speed1);
				j1.setDir(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
				j1.setMove(0.f, speed1);
				j1.setDir(4);
			}
			if(shoottimer1 < 7) shoottimer1++;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && shoottimer1>=7){
				j1.addProjectile();
				shoottimer1 = 0;
				j1.setGun(j1.getGun()-1);
			}
			//test colision
			if(colisionEnvironment(j1))
				j1.setPos(backP1x,backP1y);
			colectAllObject(j1);
//j2
			float backP2x = j2.getPosx();
			float backP2y = j2.getPosy();
//déplacement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
				j2.setMove(-speed2, 0.f);
				j2.setDir(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
				j2.setMove(speed2, 0.f);
				j2.setDir(2);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
				j2.setMove(0.f, -speed2);
				j2.setDir(3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
				j2.setMove(0.f, speed2);
				j2.setDir(4);
			}
			if(shoottimer2 < 10) shoottimer2++;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && shoottimer2>=10){
				j2.addProjectile();
				shoottimer2 = 0;
			}
//test colision
		if(colisionEnvironment(j2))
			j2.setPos(backP2x,backP2y);
		colectAllObject(j2);

		updateProjectile(j1,j2);
		updateProjectile(j2,j1);
		updateText();

}

//----------------AFFICHAGE
/*
void Game::renderText(sf::RenderTarget& target){
	target.draw(this->textOne);
}*/

void Game::display(Renderer& renderer){
/*
	this->window->clear();//nettoie le contenu de la frame précedente
	this->map.renderPers(*this->window);//affiche le personnage
	this->bar.renderPers(*this->window);//affiche le personnage
	this->maison.renderPers(*this->window);//affiche le personnage
	this->j1.getSprite().renderPers(*this->window);//affiche le personnage
	this->j2.getSprite().renderPers(*this->window);//affiche le personnage


	this->renderText(*this->window);
	this->window->display();//affichage*/
	this->window->clear();//nettoie le contenu de la frame précedente
	for( auto *e : environments ){e->display(renderer);}
	this->j1.display(renderer);//affiche le personnage
	this->j2.display(renderer);//affiche le personnage
	for(auto *l : this->lasers){l->display(renderer);}
	for(auto *l : this->guns){l->display(renderer);}
	for(auto *h : this->healths){h->display(renderer);}
	for(auto *s : this->speeds){s->display(renderer);}
	for(auto *a : this->attacks){a->display(renderer);}
	for(auto *l : j1.getProjectile()){l->display(renderer);}
	for(auto *l : j2.getProjectile()){l->display(renderer);}
	this->window->draw(this->j1Text);
	this->window->draw(this->j2Text);
	this->window->draw(this->timer1);
	this->window->draw(this->Arme1);
	this->window->draw(this->Arme2);

	this->window->display();//affichage*/

}
