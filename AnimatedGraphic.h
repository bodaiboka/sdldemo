#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numFrames);
	~AnimatedGraphic();
	void update();

private:
	int m_numFrames;
	int m_animSpeed;

};

