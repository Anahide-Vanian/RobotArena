#include "Player.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Player::Player(){

	this->initObject("robot1.png",25.f,250.f);

}
//getters / setters

sf::Sprite Player::getSprite(){ return this->sprite; }

const sf::FloatRect Player::getSpriteBounds() const{ return this->sprite.getGlobalBounds(); }

void Player::setPos(float xpos, float ypos){ this->sprite.setPosition(xpos,ypos);}

void Player::setMove(float xpos, float ypos){this->sprite.move(xpos,ypos);}

float Player::getPosx(){return this->sprite.getPosition().x;}

float Player::getPosy(){return this->sprite.getPosition().y; }

void Player::addProjectile(){
	this->projectiles.push_back(new Projectile(getPosx(),getPosy(),getDir()));
	std::cout << "new projectile" << std::endl;
}
void Player::deleteProjectile(int i){
	this->projectiles.erase(this->projectiles.begin() + i);
}

//fonctions
void Player::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(10,0, 50, 60));
	this->sprite.setOrigin(25.f, 25.f);
	this->sprite.setPosition(x,y);

	this->speed = 8;
	this->attack = 5;
	this->hp = 150;
	this->maxhp = 150;
	this->sword = 1;
	this->gun = 0;
	this->laser = 0;
	this->dir = 2;

}
// Display methods

void Player::display(Renderer& renderer) const
{
    renderer.displayPlayer(this->sprite);
}
