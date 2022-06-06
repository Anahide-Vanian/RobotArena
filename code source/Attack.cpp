#include "Attack.hpp"

//Constructors/Destructors
Attack::Attack(){
	this->initObject();
}


//getters/setters

//fonctions
//initialise le sprite et sa texture
void Attack::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("attack.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.5f, 0.5f);//resize sprite
	this->initRandomPosition();//random position
}

//affichage du sprite de notre objet
void Attack::display(Renderer& renderer) const
{
    renderer.displayAttack(this->sprite);
}

//augmente les points d'attaque du joueur de 1
void Attack::gainStat(Player& player){
  	player.setAttack(player.getAttack()+1);
}

