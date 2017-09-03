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
	m_velocity.setX(0);
	m_velocity.setY(0);
	//m_position.setX(m_position.getX() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(0.05);
	handleInput();
	
	
	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(VELOCITY);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
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


	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		//std::cout << "inputhander joystick init\n";
		if (TheInputHandler::Instance()->getJoyXValue(0, 1) > 0 ||
			TheInputHandler::Instance()->getJoyXValue(0, 1) < 0)
		{
			std::cout << "inputhander joystick init\n";
			m_velocity.setX(VELOCITY * TheInputHandler::Instance()->getJoyXValue(0,1));
		}
		if (TheInputHandler::Instance()->getJoyYValue(0, 1) > 0 ||
			TheInputHandler::Instance()->getJoyYValue(0, 1) < 0)
		{
			std::cout << "inputhander joystick init\n";
			m_velocity.setY(VELOCITY * TheInputHandler::Instance()->getJoyYValue(0, 1));
		}
	}

	if (m_velocity.getX() < 0) 
	{
		m_bHorizontalFlip = true;
	}
	else
	{
		m_bHorizontalFlip = false;
	}
}
