#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const { return s_menuId; }

private:
	static const std::string s_menuId;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static void s_menuToHeli();
};

