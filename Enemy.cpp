#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams)
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
	m_velocity.setX(0.5f);
	m_velocity.setY(0.5f);
	//m_currentFrame = int(((SDL_GetTicks() / 70) % 6));
	SDLGameObject::update();
}

void Enemy::clean()
{
}
