#include "HeliState.h"
#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "Heli.h"

const std::string HeliState::s_heliId = "HELI";

HeliState::HeliState()
{
}


HeliState::~HeliState()
{
}

void HeliState::update()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->update();
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->changeState(new MenuState());
	}
}

void HeliState::render()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->draw();
	}
}

bool HeliState::onEnter()
{

	if (!TextureManager::Instance()->load("assets/helicopter-spritesheet.png", "HELI", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* pHeli = new Heli(new LoaderParams(100, 100, 423, 150, "HELI"));
	m_gameObjects.push_back(pHeli);
	return true;
}

bool HeliState::onExit()
{
	for (GameObject* pGameObject : m_gameObjects)
	{
		pGameObject->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("HELI");
	return true;
}
