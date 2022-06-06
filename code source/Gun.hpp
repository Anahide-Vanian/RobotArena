#ifndef GUN_HPP
#define GUN_HPP

#include "Arme.hpp"
#include <iostream>

class Gun: public Arme{

	public:
	//Constructors/Destructors
	Gun();

	//getters/setters

	//fonctions

	void initObject();
	void display(Renderer& renderer) const;
	void gainStat(Player& player);


};

#endif
