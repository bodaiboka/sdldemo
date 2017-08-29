#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "InputHandler.h"
#include "MenuState.h"

const std::string PlayState::s_playId = "PLAY";

PlayState::PlayState()
{
}


PlayState::~PlayState()
{
}

void PlayState::update()
{
	// todo
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->changeState(new MenuState());
	}
}

void PlayState::render()
{
	// todo
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool PlayState::onEnter()
{
	std::cout << "load textures...\n";
	if (TextureManager::Instance()->load("assets/cat-alpha.png", CAT_TEXTURE, Game::Instance()->getRenderer()) &&
		TextureManager::Instance()->load("assets/ffvsmall.png", BOT_TEXTURE, Game::Instance()->getRenderer()) &&
		TextureManager::Instance()->load("assets/background.png", BACKGROUND, Game::Instance()->getRenderer()))
	{
		std::cout << "load textures success\n";
	}
	else
	{
		std::cout << "load textures fail\n";
		return false;
	}
	std::cout << "load game objects...\n";
	m_gameObjects.push_back(new SDLGameObject(new LoaderParams(0, 0, 800, 600, BACKGROUND)));
	m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 120, 120, BOT_TEXTURE)));
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 128, CAT_TEXTURE)));
	m_gameObjects.push_back(new Enemy(new LoaderParams(200, 0, 120, 120, BOT_TEXTURE)));

	std::cout << "entering playState\n";
	return true;
}

bool PlayState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap(BACKGROUND);
	TextureManager::Instance()->clearFromTextureMap(CAT_TEXTURE);
	TextureManager::Instance()->clearFromTextureMap(BOT_TEXTURE);

	std::cout << "exiting playState\n";
	return true;
}

