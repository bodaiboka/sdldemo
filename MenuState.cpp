#include "MenuState.h"
#include <iostream>
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "HeliState.h"

const std::string MenuState::s_menuId = "MENU";

MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::update()
{
	// todo
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
}

void MenuState::render()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/playbutton.png", "PLAY_BUTTON", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("assets/exitbutton.png", "EXIT_BUTTON", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("assets/helibutton.png", "HELI_BUTTON", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 50, 400, 100, "PLAY_BUTTON"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 250, 400, 100, "HELI_BUTTON"), s_menuToHeli);
	GameObject* button3 = new MenuButton(new LoaderParams(100, 450, 400, 100, "EXIT_BUTTON"), s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button3);

	std::cout << "entering menuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("PLAY_BUTTON");
	TextureManager::Instance()->clearFromTextureMap("EXIT_BUTTON");
	TextureManager::Instance()->clearFromTextureMap("HELI_BUTTON");
	std::cout << "exiting menuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "play button clicked\n";
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	std::cout << "exit button clicked\n";
	Game::Instance()->quit();
}

void MenuState::s_menuToHeli()
{
	std::cout << "Heli button clicked\n";
	Game::Instance()->getStateMachine()->changeState(new HeliState());
}
