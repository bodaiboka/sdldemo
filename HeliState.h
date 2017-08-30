#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class HeliState : public GameState
{
public:
	HeliState();
	~HeliState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const { return s_heliId; }

private:
	static const std::string s_heliId;
	std::vector<GameObject*> m_gameObjects;
	const std::string CAT_TEXTURE = "cat-alpha-texture";
	const std::string BOT_TEXTURE = "bot_texture";
	const std::string BACKGROUND = "background";
};

