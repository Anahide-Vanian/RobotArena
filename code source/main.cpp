#include "Game.hpp"
#include "Renderer.hpp"
//#include "Player.hpp"
//#include "Environment.hpp"
#include <iostream>

int main(){

	srand(static_cast<unsigned>(time(NULL)));

	Renderer render;
	Game game = Game(render);
	game.display(render);
	//début jeu
	while(game.running()){

		//Update
		game.update();
		
		//Render
    game.display(render);

		game.exit();
	}

	//fin du jeu
	return 0;
}
