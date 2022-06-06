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
	sf::Event event;
	//elements du jeu
	//joueur
	Player j1;
	Player j2;
	//ENVIRONMENT / DECOR
	std::vector<Environment*> environments;
	//ARME
	std::vector<Laser*> lasers;
	std::vector<Gun*> guns;
	//BONUS
	std::vector<Health*> healths;
	std::vector<Attack*> attacks;
	std::vector<Speed*> speeds;

	//TEXTE
	sf::Font font;
	sf::Text j1Text,j2Text,Arme1,Arme2,Pv1,Pv2,timer1;
	//TIMER
	sf::Clock clock;
	int oldtime;
	int shoottimer1, shoottimer2;
	//outils

	//fonctions privées

	public:

	//constructeurs /Destructeurs
	Game();
	virtual ~Game();
	Game(Renderer& renderer);

	//getters / setters

	//fonctions
	const bool running() const;//verif fenêtre toujours ouverte
	void initVariables(Renderer& render); //initialisation des éléments du jeu
	int colisionEnvironment(Player player);
	void initEnvironment(); //environment
	//arme et bonus
	void spawnArms();
	void spawnBonus();
	void respawnArme();
	void respawnBonus();
	int TestGameState();
	//texte
	void initFont();
	void initText(sf::Text& Texte , float x, float y);
	void initAllText();
	void updateText();
	//collision
	int colisionProjectile(Projectile& p);
	void updateProjectile(Player& j, Player& j2);
	int colisionProjectilePlayer(Projectile& p, Player& j);
	template<typename b>
	void colisionBonus(Player& player, std::vector<b*>& bonus);
	void colectAllObject(Player& j1); //collecte d'objet
	void update();//mise à jour de la fenêtre
	void exit();
	void display(Renderer& renderer);//affichage

};


#endif
