#include "Projectile.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Projectile::Projectile(){

	this->initObject("ball.png",0.f, 0.f);

}

Projectile::Projectile(float x, float y, int dire){

	this->initObject("ball.png", x,y);
	this->dir = dire;
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
		int speed = 80;
		if(this->dir == 1){
			this->sprite.move(-speed, 0.f);
			std::cout << "move 1" << std::endl;
		}
		else if(this->dir == 2){
			this->sprite.move(speed, 0.f);
			std::cout << "move 2" << std::endl;
		}
		else if(this->dir == 3){
			 this->sprite.move(0, -speed);
			 std::cout << "move 3" << std::endl;
		}
		else if(this->dir == 4){
			this->sprite.move(0, speed);
			std::cout << "move 4" << std::endl;
		}
		std::cout << this->getPosx() << "  " << this->getPosy() << std::endl;

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
	this->sprite.setTextureRect(sf::IntRect(0,0, 63, 63));
	this->sprite.setOrigin(25.f, 25.f);
	this->sprite.setPosition(x,y);

}
// Display methods

void Projectile::display(Renderer& renderer) const
{
    renderer.displayProjectile(this->sprite);
		std::cout << "render projectile" << std::endl;
}
