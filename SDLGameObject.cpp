#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureId = pParams->getTextureId();
	m_currentFrame = 0;
	m_currentRow = 0;
	m_bHorizontalFlip = false;
}

SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureId, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), (m_bHorizontalFlip)?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
}
