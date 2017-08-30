#include "PauseState.h"
#include "Game.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "InputHandler.h"

const std::string PauseState::s_pauseId = "PAUSE";

PauseState::PauseState()
{
}

PauseState::~PauseState()
{
}

void PauseState::update()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
}

void PauseState::render()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool PauseState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/mainbutton.png", "MAIN", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/resumebutton.png", "RESUME", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* mainButton = new MenuButton(new LoaderParams(100, 100, 200, 80, "MAIN"), s_pauseToMain);
	GameObject* resumeButton = new MenuButton(new LoaderParams(100, 250, 200, 80, "RESUME"), s_resumePlay);
	m_gameObjects.push_back(mainButton);
	m_gameObjects.push_back(resumeButton);
	return true;
}

bool PauseState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("MAIN");
	TextureManager::Instance()->clearFromTextureMap("RESUME");
	TheInputHandler::Instance()->reset();
	return true;
}

void PauseState::s_pauseToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}
