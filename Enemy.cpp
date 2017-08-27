#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::load(int x, int y, int width, int height, std::string textureId)
{
	GameObject::load(x, y, width, height, textureId);
}

void Enemy::draw(SDL_Renderer * pRenderer)
{
	GameObject::draw(pRenderer);
}

void Enemy::update()
{
	m_x += 1;
	m_y += 1;
	m_currentFrame = int(((SDL_GetTicks() / 70) % 6));
}

void Enemy::clean()
{
}
