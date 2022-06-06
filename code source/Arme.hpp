#ifndef ARME_HPP
#define ARME_HPP

#include "Object.hpp"
#include "Player.hpp"


class Arme : public Object{

	public:
	//Constructors/Destructors
	Arme();
	//~Arme();

	//getters/setters
	const sf::FloatRect getSpriteBounds() const;
	sf::Sprite getSprite();

	//fonctions
	void initObject();
	void initObject(const char* nom, int x, int y);
	void display(Renderer& renderer) const;
	void initRandomPosition();
	void gainStat(Player& player);

	protected:
	//attributs

};

#endif
