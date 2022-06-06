#include "Player.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Player::Player(){

	this->initObject("robot1.png",25.f,250.f);

}
Player::Player(const char* nom, float x, float y){

	this->initObject(nom,x,y);

}
Player::~Player(){  //Destructeurs
/*
	for(size_t i=0; i< this->projectiles.size();i++){
		delete this->projectiles[i];
	}*/
}
//getters / setters

sf::Sprite Player::getSprite(){ return this->sprite; }   //récupère le sprite

const sf::FloatRect Player::getSpriteBounds() const{ return this->sprite.getGlobalBounds(); }  //récupère les bordures du sprite (pour les colisions )

void Player::setPos(float xpos, float ypos){ this->sprite.setPosition(xpos,ypos);}  //définis une position

void Player::setMove(float xpos, float ypos){this->sprite.move(xpos,ypos);}  //définis le mouvement du sprite joueur dans une direction en x et y

float Player::getPosx(){return this->sprite.getPosition().x;}  //récupère la position en x

float Player::getPosy(){return this->sprite.getPosition().y; }  //récupère la position en y

void Player::addProjectile(){   //crée et ajoute un projectile dans la liste de projectile de ce joueur
	this->projectiles.push_back(new Projectile(getPosx(),getPosy(),getDir()));
}
void Player::deleteProjectile(int i){ //supprime un projectile dans la liste
	this->projectiles.erase(this->projectiles.begin() + i);
}

//fonctions
void Player::initObject(const char* nom, int x, int y){   //initalise un joueur
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);  //initalisation du sprite avec une texture
	this->sprite.setTextureRect(sf::IntRect(10,0, 50, 60));  //on définis la partie du sprite
	this->sprite.setOrigin(25.f, 25.f);  //on recadre le point d'origine
	this->sprite.setPosition(x,y);  //on définis la position du joueur

	this->speed = 8;  //initalisation des stats / attributs du joueur 
	this->attack = 10;
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
