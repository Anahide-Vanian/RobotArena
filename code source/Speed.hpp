#ifndef SPEED_HPP
#define SPEED_HPP

#include "Bonus.hpp"
#include <iostream>

class Speed: public Bonus{


	public:
	//Constructors/Destructors
	Speed();

	//getters/setters

	//fonctions

	void initObject();
	void display(Renderer& renderer) const;
	void gainStat(Player& player);


};

#endif
