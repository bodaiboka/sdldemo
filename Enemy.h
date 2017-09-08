#pragma once
#include "SDLGameObject.h"
#include "BaseCreator.h"

class Enemy : public SDLGameObject
{
public:
	Enemy();
	~Enemy();

	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void load(const LoaderParams* pParams);
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

