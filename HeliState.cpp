#include "Heli.h"
#include "HeliState.h"
#include "Game.h"
#include "GameOverState.h"
#include "InputHandler.h"
#include "MenuState.h"



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
	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		Game::Instance()->getStateMachine()->pushState(new GameOverState());
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
	if (!TextureManager::Instance()->load("assets/ffvsmall.png", "FFV", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* pHeli = new Heli(new LoaderParams(100, 100, 423, 150, "HELI"));
	GameObject* pEnemy = new Enemy(new LoaderParams(600, 0, 120, 120, "FFV"));
	m_gameObjects.push_back(pHeli);
	m_gameObjects.push_back(pEnemy);
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
	TextureManager::Instance()->clearFromTextureMap("FFV");
	return true;
}

bool HeliState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (leftA >= rightB) { return false; }
	if (rightA <= leftB) { return false; }

	return true;
}
