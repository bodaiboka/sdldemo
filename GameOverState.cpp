#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "HeliState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverId = "GAMEOVER";


GameOverState::GameOverState()
{
}


GameOverState::~GameOverState()
{
}

void GameOverState::update()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
}

void GameOverState::render()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/gameover.png", "GAMEOVER", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/mainbutton.png", "MAIN", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/restartbutton.png", "RESTART", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "GAMEOVER"), 2, 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "MAIN"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "RESTART"), s_restartPlay);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}

bool GameOverState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("GAMEOVER");
	TextureManager::Instance()->clearFromTextureMap("RESTART");
	TextureManager::Instance()->clearFromTextureMap("MAIN");
	return true;
}

std::string GameOverState::getStateId() const
{
	return s_gameOverId;
}

void GameOverState::s_gameOverToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(new HeliState());
}