#include "Game.h"
#include <Windows.h>

Game* g_pGame = 0;

int main(int argc, char* args[])
{
	g_pGame = new Game();
	g_pGame->init("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while (g_pGame->running())
	{
		g_pGame->handleEvents();
		g_pGame->update();
		g_pGame->render();
		SDL_Delay(60);
	}
	g_pGame->clean();
	return 0;
}


