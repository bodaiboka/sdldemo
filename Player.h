#pragma once
#include "SDLGameObject.h"
#include "BaseCreator.h"

class Player : public SDLGameObject
{
public:
	Player();
	~Player();

	void draw();
	void update();
	void clean();
	void handleInput();
	void load(const LoaderParams* pParams);

private:
	const float VELOCITY = 3.0f;

};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const 
	{
		return new Player();
	}
};

