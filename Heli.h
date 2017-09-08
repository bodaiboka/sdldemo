#pragma once
#include "SDLGameObject.h"

class Heli : public SDLGameObject
{
public:
	Heli();
	~Heli();

	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();

	virtual void load(const LoaderParams* pParams);
};

class HeliCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Heli();
	}
};

