#pragma once
#include <vector>
#include "GameState.h"
#include "GameObject.h"
class GameOverState : public GameState
{
public:
	GameOverState();
	~GameOverState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const;

private:
	static const std::string s_gameOverId;
	static void s_gameOverToMain();
	static void s_restartPlay();

	std::vector<GameObject*> m_gameObjects;
};

