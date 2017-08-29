#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const { return s_playId; }

private:
	static const std::string s_playId;
	std::vector<GameObject*> m_gameObjects;
	const std::string CAT_TEXTURE = "cat-alpha-texture";
	const std::string BOT_TEXTURE = "bot_texture";
	const std::string BACKGROUND = "background";

};

