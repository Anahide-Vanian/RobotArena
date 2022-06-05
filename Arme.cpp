#include "Arme.hpp"
#include <iostream>


//Constructors/Destructors
Arme::Arme(){
  this->initObject();
}

//getters/setters
const sf::FloatRect Arme::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

sf::Sprite Arme::getSprite(){
		return this->sprite;
}

//fonctions

void Arme::initObject(){
	if(!this->texture.loadFromFile("laser.png")){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
}

void Arme::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(sf::Vector2f(1,1));
	this->sprite.setPosition(x,y);
}
// Display methods

void Arme::display(Renderer& renderer) const
{
    //renderer.displayArme(this->sprite);
}

void Arme::initRandomPosition(){

	//random position
	float posX = static_cast <float>(rand()% (1550-50 + 1)+50); //between 1 and target->getSize().x-1
	float posY = static_cast <float>(rand()% (850-200 + 1)+200);

	//init Position randomly
	this->sprite.setPosition(posX, posY);
}

void Arme::gainStat(Player& player){
  int hp = player.getHp();
}
