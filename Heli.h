#pragma once
#include "SDLGameObject.h"

class Heli : public SDLGameObject
{
public:
	Heli(const LoaderParams* pParams);
	~Heli();

	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();
};

