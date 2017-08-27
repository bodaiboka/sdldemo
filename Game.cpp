#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success\n";
		int flags = (fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		// init our window
		m_pWindow = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, flags);

		if (m_pWindow !=0)
		{
			cout << "window creation success\n";
			// if window creation suceeded create our renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			
			if (m_pRenderer != 0)
			{
				cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
			else
			{
				cout << "renderer init fail\n";
				return false;
			}
		}
		else
		{
			cout << "window init fail\n";
		}
	}
	else
	{
		cout << "SDL init fail\n";
		// SDL could not initialize
		return false;
	}
	cout << "init success";
	m_bRunning = true;
	return true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::render()
{
	// clear the window to drawColor
	SDL_RenderClear(m_pRenderer);

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}