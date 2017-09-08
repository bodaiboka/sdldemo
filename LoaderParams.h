#pragma once
#include <iostream>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string textureId, int numFrames, int callbackId = 0, int animSpeed = 0) :
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_textureId(textureId),
		m_numFrames(numFrames),
		m_callbackId(callbackId),
		m_animSpeed(animSpeed)
		{}
	~LoaderParams();

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getNumFrames() const { return m_numFrames; }
	int getAnimSpeed() const { return m_animSpeed; }
	int getCallbackId() const { return m_callbackId; }
	std::string getTextureId() const { return m_textureId; }

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_numFrames;
	int m_callbackId;
	int m_animSpeed;
	std::string m_textureId;
};

