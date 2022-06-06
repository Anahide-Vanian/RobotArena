#include "Attack.hpp"

//Constructors/Destructors
Attack::Attack(){
	this->initObject();
}


//getters/setters

//fonctions

void Attack::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("attack.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.5f, 0.5f);//resize sprite
	this->initRandomPosition();//random position
}

void Attack::display(Renderer& renderer) const
{
    renderer.displayAttack(this->sprite);
}

void Attack::gainStat(Player& player){
  	player.setAttack(player.getAttack()+1);
}
/*

void Attack::colisionBonus(Player player){
	for(int i=0; i<attacks.size(); i++){
		//player1 movement
		if(player.getSpriteBounds().intersects(attacks[i]->getSpriteBounds())){
			attacks.erase(attacks.begin() + i);
			std::cout << "intercept attack" << std::endl;
			//bonus->gainStat(1);
		}
}
}

void Attack::spawnBonus(){
	//sprawn lasers
	for(int i=0; i<4; i++){
		this->attacks.push_back(new Attack());
	}
}*/
