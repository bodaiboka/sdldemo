#include <iostream>
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "HeliState.h"
#include "MainMenuState.h"
#include "StateParser.h"

const std::string MainMenuState::s_menuId = "MENU";

MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{

}

void MainMenuState::update()
{
	// todo
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
}

void MainMenuState::render()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool MainMenuState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("assets/data.xml", s_menuId, &m_gameObjects, &m_textureIdList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_menuToHeli);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);
	std::cout << "entering menuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIdList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIdList[i]);
	}
	std::cout << "exiting menuState\n";
	return true;
}

void MainMenuState::s_menuToPlay()
{
	std::cout << "play button clicked\n";
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu()
{
	std::cout << "exit button clicked\n";
	Game::Instance()->quit();
}

void MainMenuState::s_menuToHeli()
{
	std::cout << "Heli button clicked\n";
	Game::Instance()->getStateMachine()->changeState(new HeliState());
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
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
