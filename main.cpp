#include "Game.h"

Game* g_pGame = 0;

int main(int argc, char* args[])
{
	g_pGame = new Game();
	g_pGame->init("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	while (g_pGame->running())
	{
		g_pGame->handleEvents();
		g_pGame->update();
		g_pGame->render();
	}
	g_pGame->clean();
	return 0;
}

