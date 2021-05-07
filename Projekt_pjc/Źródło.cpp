#include "Game.h"


int main()
{
	Game game;

	//Game loop
	while (game.running())
	{
		game.update();
		game.wyswietlanie();
	}	

	return 0;
}