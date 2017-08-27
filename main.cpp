#include <SDL.h>
#include <iostream>

using namespace std;

SDL_Window* pWindow = 0;
SDL_Renderer* pRenderer = 0;
bool bRunning = false;

bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
void render();

int main(int argc, char* args[])
{
	cout << "Hello SDL 2!" << endl;

	// init SDL
	if (init("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
	{
		bRunning = true;
	}
	else
	{
		// something's wrong
		return 1;
	}

	while (bRunning)
	{
		render();
	}
	
	// clean up SDL
	SDL_Quit();

	return 0;
}

bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		pWindow = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

		if (pWindow != 0)
		{
			// if window creation suceeded create our renderer
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		}
	}
	else
	{
		// SDL could not initialize
		return false;
	}
	return true;
}

void render()
{
	// everything succeeded lets draw the window
	SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);

	// clear the window to red
	SDL_RenderClear(pRenderer);

	// show the window
	SDL_RenderPresent(pRenderer);

	// set a delay before quitting
	// SDL_Delay(3000);
}
