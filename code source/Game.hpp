#ifndef GAME_HPP
#define GAME_HPP

#include "Object.hpp"
#include "Player.hpp"
#include "Environment.hpp"
#include "Laser.hpp"
#include "Health.hpp"
#include "Speed.hpp"
#include "Attack.hpp"
#include "Gun.hpp"
#include "Projectile.hpp"
#include "Renderer.hpp"

#include <iostream>
#include <sstream> //string stream
#include <vector>

class Game{

	private:
	//attributs
	sf::RenderWindow* window;//pointeur vers la fenêtre
	sf::VideoMode videoMode;
	sf::Event event;
	//Resources
	sf::Font fontOne;
	//Text
	sf::Text textOne;
	//elements du jeu
	Player j1;
	Player j2;
	//std::vector<Arbre> arbres;
	std::vector<Environment*> environments;
	std::vector<Laser*> lasers;
	std::vector<Gun*> guns;
	std::vector<Health*> healths;
	std::vector<Attack*> attacks;
	std::vector<Speed*> speeds;

	sf::Font font;
	sf::Text j1Text,j2Text,Arme1,Arme2,Pv1,Pv2,timer1;
	sf::Clock clock;
	int oldtime;
	int shoottimer1, shoottimer2;
	//outils
	int nbBoxesCollected;

	//fonctions privées
	//void initVariables();
	void initVariables(Renderer& render);
	int colisionEnvironment(Player player);
	void initEnvironment();
	void spawnArms();
	void spawnBonus();
	void respawnArme();
	void respawnBonus();
	//void initWindow();
	//void initFonts();
	void initFont();
	void initText(sf::Text& Texte , float x, float y);
	void initAllText();
	void updateText();
	int colisionProjectile(Projectile& p);
	void updateProjectile(Player& j, Player& j2);


	public:

	//constructeurs /Destructeurs
	Game();
	virtual ~Game();
	Game(Renderer& renderer);

	//getters / setters
	const bool running() const;//verif fenêtre toujours ouverte


	//fonctions
	int colisionProjectilePlayer(Projectile& p, Player& j);
	template<typename b>
	void colisionBonus(Player& player, std::vector<b*>& bonus);
	void colectAllObject(Player& j1);
	void update();//mise à jour de la fenêtre
	void exit();
	void display(Renderer& renderer);//affichage

};


#endif
