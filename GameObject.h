#pragma once
#include <iostream>
#include <SDL.h>
#include "TextureManager.h"
using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void load(int x, int y, int width, int height, std::string textureId);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

protected:
	int m_x;
	int m_y;
	int m_currentFrame;
	int m_currentRow;
	int m_width;
	int m_height;
	std::string m_textureId;
};

