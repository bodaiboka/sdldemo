#include "GameOverState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "HeliState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "StateParser.h"

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
	StateParser stateParser;
	stateParser.parseState("assets/data.xml", s_gameOverId, &m_gameObjects, &m_textureIdList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	setCallbacks(m_callbacks);
	return true;
}

bool GameOverState::onExit()
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
	return true;
}

std::string GameOverState::getStateId() const
{
	return s_gameOverId;
}

void GameOverState::s_gameOverToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(new HeliState());
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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
