#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Bonus.hpp"
#include <iostream>

class Health: public Bonus{

	public:
	//Constructors/Destructors
	Health();

	//getters/setters

	//fonctions

	void initObject();
	void display(Renderer& renderer) const;
	void gainStat(Player& player);


};

#endif
