#include "Bonus.hpp"
#include <iostream>


//Constructors/Destructors
Bonus::Bonus(){
  this->initObject();
}

//getters/setters
const sf::FloatRect Bonus::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

sf::Sprite Bonus::getSprite(){
		return this->sprite;
}

//fonctions

void Bonus::initObject(){
	if(!this->texture.loadFromFile("laser.png")){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
}

void Bonus::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(sf::Vector2f(1,1));
	this->sprite.setPosition(x,y);
}
// Display methods

void Bonus::display(Renderer& renderer) const
{
    //renderer.displayArme(this->sprite);
}

void Bonus::initRandomPosition(){

	//random position
	float posX = static_cast <float>(rand()% (1550-50 + 1)+50); //between 1 and target->getSize().x-1
	float posY = static_cast <float>(rand()% (850-200 + 1)+200);

	//init Position randomly
	this->sprite.setPosition(posX, posY);
}

void Bonus::gainStat(Player& player){
  int hp = player.getHp();
}
