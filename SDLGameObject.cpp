#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams)
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureId = pParams->getTextureId();
	m_currentFrame = 0;
	m_currentRow = 0;
}


SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureId, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
}

void SDLGameObject::clean()
{
}
