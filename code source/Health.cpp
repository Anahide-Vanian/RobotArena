#include "Health.hpp"


//Constructors/Destructors
Health::Health(){
	this->initObject();
}


//getters/setters

//fonctions

void Health::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("health.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.5f, 0.5f);//resize sprite
	this->initRandomPosition();//random position
}

void Health::display(Renderer& renderer) const
{
    renderer.displayHealth(this->sprite);
}

void Health::gainStat(Player& player){
  	player.setHp(player.getHp()+15);
		player.setMaxhp(player.getMaxhp()+15);
}
