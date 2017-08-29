#pragma once
#include <string>

class GameState
{
public:
	GameState();
	~GameState();

	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateId() const = 0;

};
