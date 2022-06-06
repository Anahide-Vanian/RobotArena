#include "Game.hpp"
#include "Renderer.hpp"
//#include "Player.hpp"
//#include "Environment.hpp"
#include <iostream>

int main(){

	srand(static_cast<unsigned>(time(NULL)));//nécessaire à la randomisation dans jeu 

	Renderer render; //crée la fenêtre
	Game* game = new Game(render); //crée le jeu
	//début jeu
	while(game->running()){

		//Update
		game->update();

		//Render
    	game->display(render);

		game->exit();
	}
	delete game;//destruction de la fuite mémoire

	//fin du jeu
	return 0;
}
