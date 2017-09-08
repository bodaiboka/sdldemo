#include "Game.h"
#include "SDLGameObject.h"

SDLGameObject::SDLGameObject() : GameObject()
{
}

SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureId, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), (m_bHorizontalFlip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
	
}

void SDLGameObject::clean()
{
}

void SDLGameObject::load(const LoaderParams * pParams)
{
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_velocity = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureId = pParams->getTextureId();
	m_currentFrame = 0;
	m_currentRow = 0;
	m_numFrames = pParams->getNumFrames();
	m_bHorizontalFlip = false;
}
