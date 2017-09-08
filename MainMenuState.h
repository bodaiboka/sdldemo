#pragma once
#include "MenuState.h"
#include <vector>
#include "GameObject.h"

class MainMenuState : public MenuState
{
public:
	MainMenuState();
	~MainMenuState();

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

	virtual void setCallbacks(const std::vector<Callback> & callbacks);
};

