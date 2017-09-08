#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic();
	~AnimatedGraphic();
	void update();
	virtual void load(const LoaderParams* pParams);

private:
	int m_animSpeed;

};

class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};

