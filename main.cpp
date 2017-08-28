#include "Game.h"
#include <Windows.h>
using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 framesStart, frameTime;

	if (Game::Instance()->init("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true))
	{
		while (Game::Instance()->running())
		{
			framesStart = SDL_GetTicks();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
			frameTime = SDL_GetTicks() - framesStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)DELAY_TIME - frameTime);
			}
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


