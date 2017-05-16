#include <stdlib.h>
#include "../include/Game.hpp"
#include <iostream>

int main(int argc, char *argv[]){
	Game* game = new Game("first_game", 1024, 600);

	game->run();

	delete(game);

	return 0;
}