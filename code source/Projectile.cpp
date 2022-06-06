#include "Projectile.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
//constructeur du projectile par défaut
Projectile::Projectile(){

	this->initObject("ball.png",0.f, 0.f);

}
//constructeur du projectile: on le positionne en x, y et on choisi sa direction de déplacement
Projectile::Projectile(float x, float y, int dire){

	this->initObject("ball.png", x,y);
	this->dir = dire;   //Initalise la direction du projectile au moment de la création du projectile
}
//getters / setters
//obtenrion du sprite 
sf::Sprite Projectile::getSprite(){
		return this->sprite;
}

//obtention des bords du sprite
const sf::FloatRect Projectile::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

//positionner le projectile en xpos et ypos
void Projectile::setPos(float xpos, float ypos){
		this->sprite.setPosition(xpos,ypos);
}

//défini le mouvement d'un projectile d'une frame a une autre en fonction de la direction au moment de la création du projectile
void Projectile::setMove(Player& p){
		int speed = 80;
		if(this->dir == 1){   //MOVE GAUCHE
			this->sprite.move(-speed, 0.f);
		}
		else if(this->dir == 2){  //MOVE DROITE
			this->sprite.move(speed, 0.f);
		}
		else if(this->dir == 3){  //MOVE HAUT
			 this->sprite.move(0, -speed);
		}
		else if(this->dir == 4){ //MOVE BAS
			this->sprite.move(0, speed);
		}

}

//obtention de la position en x du sprite
float Projectile::getPosx(){   //RÉCUPÈRE LA POSITION DU PROJECTILE
		return this->sprite.getPosition().x;
}
//obtention de la position en y du sprite
float Projectile::getPosy(){
		return this->sprite.getPosition().y;
}

//fonctions
//initialise un projectile avec un sprite
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
//affichage du projectile
void Projectile::display(Renderer& renderer) const
{
    renderer.displayProjectile(this->sprite);
}
