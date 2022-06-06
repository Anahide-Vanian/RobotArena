#include "Speed.hpp"

//Constructors/Destructors
//constructeur de l'objet'
Speed::Speed(){
	this->initObject();
}


//getters/setters

//fonctions
//initialise le sprite de l'objet avec sa texture et sa position'
void Speed::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("speed.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.2f, 0.2f);//resize sprite
	this->initRandomPosition();//random position
}
//affichage du sprite
void Speed::display(Renderer& renderer) const
{
    renderer.displaySpeed(this->sprite);
}

//augmente la vitesse du joueur de 1
void Speed::gainStat(Player& player){
  	player.setSpeed(player.getSpeed()+1);
}
