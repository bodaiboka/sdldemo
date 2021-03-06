#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::s_pInstance = NULL;

GameObjectFactory::GameObjectFactory()
{
}

GameObjectFactory::~GameObjectFactory()
{
}

bool GameObjectFactory::registerType(std::string typeId, BaseCreator * pCreator)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeId);

	if (it != m_creators.end())
	{
		delete pCreator;
		return false;
	}
	
	m_creators[typeId] = pCreator;

	return true;
}

GameObject * GameObjectFactory::create(std::string typeId)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeId);
	if (it == m_creators.end())
	{
		std::cout << "couldn't find type: " << typeId << "\n";
		return NULL;
	}
	BaseCreator* pCreator = (*it).second;
	return pCreator->createGameObject();
}
