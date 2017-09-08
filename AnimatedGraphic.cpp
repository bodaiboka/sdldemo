#include "AnimatedGraphic.h"



AnimatedGraphic::AnimatedGraphic() 
{
}


AnimatedGraphic::~AnimatedGraphic()
{
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}
