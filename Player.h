#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	~Player();

	void draw();
	void update();
	void clean();

private:
	const float VELOCITY = 3.0f;

};
