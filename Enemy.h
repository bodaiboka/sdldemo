#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual void load(int x, int y, int width, int height, std::string textureId);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();
};

