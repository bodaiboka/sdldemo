#pragma once
#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	std::string m_textureId;
};

