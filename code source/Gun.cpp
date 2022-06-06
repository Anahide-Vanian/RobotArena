#include "Gun.hpp"

//Constructors/Destructors
Gun::Gun(){
	this->initObject();
}


//getters/setters

//fonctions

void Gun::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("gun.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.2f, 0.2f);//resize sprite
	this->initRandomPosition();//random position
}

void Gun::display(Renderer& renderer) const
{
    renderer.displayArmeGun(this->sprite);
}

void Gun::gainStat(Player& player){
  	player.setGun(player.getGun()+12);
}
