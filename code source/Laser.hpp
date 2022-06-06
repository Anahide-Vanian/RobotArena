#ifndef LASER_HPP
#define LASER_HPP

#include "Arme.hpp"
#include <iostream>

class Laser: public Arme{

	public:
	//Constructors/Destructors
	Laser();

	//getters/setters

	//fonctions

	void initObject();
	void display(Renderer& renderer) const;
	void gainStat(Player& player);


};

#endif
