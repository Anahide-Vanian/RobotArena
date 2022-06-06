#include "Bonus.hpp"
#include <iostream>


//Constructors/Destructors
Bonus::Bonus(){
  this->initObject();
}

//getters/setters

//retourne les bords de notre sprite
const sf::FloatRect Bonus::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

//retourne le sprite
sf::Sprite Bonus::getSprite(){
		return this->sprite;
}

//fonctions
//initialise le sprite et sa texture
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
//affichage du sprite
void Bonus::display(Renderer& renderer) const
{
    //renderer.displayArme(this->sprite);
}

//initialise le sprite, sa texture, sa taille et sa position
void Bonus::initRandomPosition(){

	//random position
	float posX = static_cast <float>(rand()% (1550-50 + 1)+50); //between 1 and target->getSize().x-1
	float posY = static_cast <float>(rand()% (850-200 + 1)+200);

	//init Position randomly
	this->sprite.setPosition(posX, posY);
}

//augmente les points de Bonus du joueur 
void Bonus::gainStat(Player& player){
  int hp = player.getHp();
}
