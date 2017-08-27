#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::load(int x, int y, int width, int height, std::string textureId)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureId = textureId;
	m_currentFrame = 0;
	m_currentRow = 0;
}

void GameObject::draw(SDL_Renderer * pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureId, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update()
{
	m_x -= 1;
}

void GameObject::clean()
{
}
