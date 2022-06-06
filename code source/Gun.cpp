#include "Gun.hpp"

//Constructors/Destructors
Gun::Gun(){
	this->initObject();
}


//getters/setters

//fonctions
//initialise le sprite, sa texture, sa taille et sa position
void Gun::initObject(){
	//init Texture and sprite
	if(!(this->texture.loadFromFile("gun.png"))){
		std::cout << "ERROR::Game::INITVARIABLES:: Failed to load texture !" << "\n";
	}
	this->sprite.setTexture(this->texture);
	//this->sprite.setScale(0.2f, 0.2f);//resize sprite
	this->initRandomPosition();//random position
}
//affichage du sprite
void Gun::display(Renderer& renderer) const
{
    renderer.displayArmeGun(this->sprite);
}

//augmente les points munitions du joueur pour pouvoir utiliser le pistolet et attaquer
void Gun::gainStat(Player& player){
  	player.setGun(player.getGun()+12);  // si le joueur collecte un gun, il y a 12 munitions de gun en plus
}
