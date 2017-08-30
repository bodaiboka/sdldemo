#pragma once
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class PauseState : public GameState
{
public:
	PauseState();
	~PauseState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const { return s_pauseId; }

private:
	static const std::string s_pauseId;
	std::vector<GameObject*> m_gameObjects;
	static void s_pauseToMain();
	static void s_resumePlay();
};

