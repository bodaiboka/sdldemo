#pragma once
#include <string>
#include <map>
#include "GameObject.h"

class BaseCreator
{
public:
	BaseCreator();
	virtual ~BaseCreator();

	virtual GameObject* createGameObject() const = 0;
};

