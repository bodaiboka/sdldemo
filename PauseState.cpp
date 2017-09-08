#include "PauseState.h"
#include "Game.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "InputHandler.h"
#include "StateParser.h"

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
	StateParser stateParser;
	stateParser.parseState("assets/data.xml", s_pauseId, &m_gameObjects, &m_textureIdList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);
	/*
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
	*/
	return true;
}

bool PauseState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	for (std::string id : m_textureIdList)
	{
		TextureManager::Instance()->clearFromTextureMap(id);
	}
	TheInputHandler::Instance()->reset();
	return true;
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackId()]);
		}
	}
}

void PauseState::s_pauseToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}
