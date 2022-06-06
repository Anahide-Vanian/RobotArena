#include "Speed.hpp"

//Constructors/Destructors
Speed::Speed(){
	this->initObject();
}


//getters/setters

//fonctions

void Speed::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("speed.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.2f, 0.2f);//resize sprite
	this->initRandomPosition();//random position
}

void Speed::display(Renderer& renderer) const
{
    renderer.displaySpeed(this->sprite);
}
void Speed::gainStat(Player& player){
  	player.setSpeed(player.getSpeed()+1);
}
