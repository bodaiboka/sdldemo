#pragma once
#include "BaseCreator.h"

class GameObjectFactory
{
public:
	static GameObjectFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameObjectFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}
	~GameObjectFactory();
	bool registerType(std::string typeId, BaseCreator* pCreator);
	GameObject* create(std::string typeId);

private:
	static GameObjectFactory* s_pInstance;
	GameObjectFactory();
	std::map<std::string, BaseCreator*> m_creators;
};
typedef GameObjectFactory TheGameObjectFactory;

