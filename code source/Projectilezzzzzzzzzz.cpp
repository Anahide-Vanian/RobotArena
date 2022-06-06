#include "Projectile.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Projectile::Projectile(){

	this->initObject("gun.png",0.f, 0.f);

}

Projectile::Projectile(float x, float y){

	this->initObject("gun.png", x,y);

}
//getters / setters

sf::Sprite Projectile::getSprite(){
		return this->sprite;
}

const sf::FloatRect Projectile::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

void Projectile::setPos(float xpos, float ypos){
		this->sprite.setPosition(xpos,ypos);
}

void Projectile::setMove(Player& p){
		int speed = 25;
		if(p.getDir() == 1) this->sprite.move(-speed, 0.f);
		else if(p.getDir() == 2) this->sprite.move(speed, 0.f);
		else if(p.getDir() == 3) this->sprite.move(0, -speed);
		else if(p.getDir() == 4) this->sprite.move(0, speed);
}

float Projectile::getPosx(){
		return this->sprite.getPosition().x;
}

float Projectile::getPosy(){
		return this->sprite.getPosition().y;
}

//fonctions
void Projectile::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setTextureRect(sf::IntRect(10,0, 50, 60));
	this->sprite.setOrigin(25.f, 25.f);
	this->sprite.setPosition(x,y);

}
// Display methods

void Projectile::display(Renderer& renderer) const
{
    renderer.displayProjectile(this->sprite);
}
