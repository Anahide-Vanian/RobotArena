#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "Bonus.hpp"
#include <iostream>

class Attack: public Bonus{

	public:
	//Constructors/Destructors
	Attack();

	//getters/setters

	//fonctions

	void initObject();
	void display(Renderer& renderer) const;
	void gainStat(Player& player);
	/*
	void colisionBonus(Player player);

private:
	std::vector<Attack*> attacks;*/


};

#endif
