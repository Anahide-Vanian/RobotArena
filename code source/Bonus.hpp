#ifndef BONUS_HPP
#define BONUS_HPP

#include "Object.hpp"
#include "Player.hpp"


class Bonus : public Object{


	public:
	//Constructors/Destructors
	Bonus();
	//~Bonus();

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
