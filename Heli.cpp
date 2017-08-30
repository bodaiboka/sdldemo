#include "Heli.h"
#include "InputHandler.h"

Heli::Heli(const LoaderParams* pParams) :
	SDLGameObject(pParams)
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
