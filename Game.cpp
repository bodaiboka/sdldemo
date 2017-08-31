#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
using namespace std;
Game::Game()
{
}

Game::~Game()
{
}

Game* Game::s_pInstance = 0;

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
	cout << "init success\n";
	
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	TheInputHandler::Instance()->initialiseJoysticks();

	m_bRunning = true;
	return true;
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
	/*
	for (GameObject* object : m_gameObjects)
	{
		object->update();
	}
	*/
	//m_currentFrame = int(((SDL_GetTicks() / 70) % 6));
}

void Game::render()
{
	// clear the window to drawColor
	SDL_RenderClear(m_pRenderer);

	// draw texture
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRect, &m_destinationRect);
	//SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRect, &m_destinationRect, 0, 0, SDL_FLIP_HORIZONTAL);
	//TextureManager::Instance()->draw(CAT_TEXTURE, 0, 0, 128, 128, m_pRenderer);
	//TextureManager::Instance()->drawFrame(CAT_TEXTURE, 300, 160, 128, 128, 0, m_currentFrame, m_pRenderer);

	/*
	for (GameObject* object : m_gameObjects)
	{
		object->draw();
	}
	*/

	m_pGameStateMachine->render();


	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}
