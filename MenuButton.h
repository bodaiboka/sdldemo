#pragma once
#include "SDLGameObject.h"
#include "BaseCreator.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton();
	~MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackId() { return m_callbackId; }

private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	void(*m_callback)();
	bool m_bReleased;
	int m_callbackId;

};

class MenuBUttonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};

