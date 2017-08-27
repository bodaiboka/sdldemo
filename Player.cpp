#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::load(int x, int y, int width, int height, std::string textureId)
{
	GameObject::load(x, y, width, height, textureId);
}

void Player::draw(SDL_Renderer * pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::update()
{
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 70) % 6));
}

void Player::clean()
{
}
