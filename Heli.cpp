#include "Heli.h"
#include "InputHandler.h"

Heli::Heli() :
	SDLGameObject()
{
}

Heli::~Heli()
{
}

void Heli::draw()
{
	SDLGameObject::draw();
}

void Heli::update()
{
	if (m_velocity.getX() >= 0)
	{
		m_bHorizontalFlip = false;
	}
	else
	{
		m_bHorizontalFlip = true;
	}
	m_currentRow = int(((SDL_GetTicks() / 100) % 4));
	handleInput();
	SDLGameObject::update();
}

void Heli::clean()
{
}

void Heli::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Heli::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
}
