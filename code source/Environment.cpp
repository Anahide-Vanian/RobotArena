#include "Environment.hpp"
#include <iostream>


//fonctions privées


//constructeurs /Destructeurs
Environment::Environment(){

	this->initObject();

}

//creation d'un environnement de jeu 
Environment::Environment(const char* nom, int x, int y){

	this->initObject(nom, x, y);

}
//getters / setters
//obtention du sprite
sf::Sprite Environment::getSprite(){
		return this->sprite;
}

//obtention des bordures de notre sprite
const sf::FloatRect Environment::getSpriteBounds() const{
	return this->sprite.getGlobalBounds();
}

//fonctions
//initialisation de l'environnement par défaut
void Environment::initObject(){

}

//initialise le sprite, sa texture, sa taille et sa position
void Environment::initObject(const char* nom, int x, int y){
	if(!this->texture.loadFromFile(nom)){
		std::cout << "load fail" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(sf::Vector2f(1,1));
	this->sprite.setPosition(x,y);
}
// Display methods
//affichage du sprite de l'environnement
void Environment::display(Renderer& renderer) const
{
    renderer.displayEnvironment(this->sprite);
}
