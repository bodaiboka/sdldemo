#include "Enemy.h"

Enemy::Enemy() :
	SDLGameObject()
{
	
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	if (m_position.getY() > 500)
	{
		m_velocity.setY(-2);
	}
	//m_currentFrame = int(((SDL_GetTicks() / 70) % 6));
	SDLGameObject::update();
}

void Enemy::clean()
{
}

void Enemy::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_velocity.setX(0.001);
	m_velocity.setY(2);
}
