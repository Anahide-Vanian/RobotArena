#include "DynamicObject.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
DynamicObject::DynamicObject(){

	this->initObject("robot1.png",25.f,250.f);

}
//getters / setters


//fonctions
//initialise le sprite, sa texture avec sa position
void DynamicObject::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile("robot1.png")){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0,0, 0, 0));
	this->sprite.setPosition(0,0);

}
// Display methods

void DynamicObject::display(Renderer& renderer) const
{
    //renderer.displayDynamicObject(this->sprite);
}
