#include "Environment.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Environment::Environment(){

	this->initObject();

}

Environment::Environment(const char* nom, int x, int y){

	this->initObject(nom, x, y);

}
//getters / setters
sf::Sprite Environment::getSprite(){
		return this->sprite;
}
const sf::FloatRect Environment::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

//fonctions

void Environment::initObject(){

}

void Environment::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(sf::Vector2f(1,1));
	this->sprite.setPosition(x,y);
}
// Display methods

void Environment::display(Renderer& renderer) const
{
    renderer.displayEnvironment(this->sprite);
}
