#include "Game.h"
#include <math.h>
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
		m_pWindow = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		if (m_pWindow !=0)
		{
			cout << "window creation success\n";
			// if window creation suceeded create our renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			
			if (m_pRenderer != 0)
			{
				cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/cat.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRect.w, &m_sourceRect.h);
	m_destinationRect.x = m_sourceRect.x = 0;
	m_sourceRect.y = 0;
	m_destinationRect.y = 160;
	m_sourceRect.y = 0;
	m_destinationRect.w = m_sourceRect.w = 128;
	m_destinationRect.h = m_sourceRect.h = 128;
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

void Game::update()
{
	m_sourceRect.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
	// clear the window to drawColor
	SDL_RenderClear(m_pRenderer);

	// draw texture
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRect, &m_destinationRect);
	//SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRect, &m_destinationRect, 0, 0, SDL_FLIP_HORIZONTAL);

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}