#include "Game.h"

int main(int argc, char* argv[])
{
	Game game(640, 480, "sdlPong");

	while (game.isRunning())
	{
		game.handleInput();
		game.update();
		game.render();
	}

	return 0;
}