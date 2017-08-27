#include "Game.h"
#include <Windows.h>
using namespace std;

int main(int argc, char* args[])
{
	if (Game::Instance()->init("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false))
	{
		while (Game::Instance()->running())
		{
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
			SDL_Delay(60);
		}
	}
	else
	{
		cout << "Game init failure - " << SDL_GetError() << endl;
		return -1;
	}
	cout << "Game closing...\n";
	Game::Instance()->clean();
	return 0;
}


