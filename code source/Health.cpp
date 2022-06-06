#include "Health.hpp"


//Constructors/Destructors
//constructeur de notre objet
Health::Health(){
	this->initObject();
}


//getters/setters

//fonctions
//initialise le sprite, sa texture, sa taille et sa position
void Health::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("health.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.5f, 0.5f);//resize sprite
	this->initRandomPosition();//random position
}

//affichage du sprite
void Health::display(Renderer& renderer) const
{
    renderer.displayHealth(this->sprite);
}

//augmente les points de vie du joueur de 15
void Health::gainStat(Player& player){
  	player.setHp(player.getHp()+15);  //vie + 15
		player.setMaxhp(player.getMaxhp()+15); //vie max +15
}
