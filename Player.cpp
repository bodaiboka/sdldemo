#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}

Player::~Player()
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	//m_position.setX(m_position.getX() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(0.05);
	m_velocity.setX(0);
	m_velocity.setY(0);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_bHorizontalFlip = false;
		m_velocity.setX(VELOCITY);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_bHorizontalFlip = true;
		m_velocity.setX(-VELOCITY);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-VELOCITY);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(VELOCITY);
	}
	SDLGameObject::update();
}

void Player::clean()
{
}
