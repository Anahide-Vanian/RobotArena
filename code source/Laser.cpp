#include "Laser.hpp"

//Constructors/Destructors
Laser::Laser(){
	this->initObject();
}


//getters/setters

//fonctions

void Laser::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("laser.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.2f, 0.2f);//resize sprite
	this->initRandomPosition();//random position
}

void Laser::display(Renderer& renderer) const
{
    renderer.displayArmeLaser(this->sprite);
}

void Laser::gainStat(Player& player){
  	player.setLaser(player.getLaser()+3);
}
