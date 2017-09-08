#include "StateParser.h"
#include "Game.h"
#include "GameObjectFactory.h"

StateParser::StateParser()
{
}


StateParser::~StateParser()
{
}

bool StateParser::parseState(const char * stateFile, std::string stateId, std::vector<GameObject*>* pObjects, std::vector<std::string>* pTextureIds)
{
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(stateFile))
	{

		std::cout << xmlDoc.ErrorDesc() << "\n";
		return false;
	}

	TiXmlElement* pRoot = xmlDoc.RootElement();
	TiXmlElement* pStateRoot = 0;
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateId)
		{
			pStateRoot = e;
		}
	}

	TiXmlElement* pTextureRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}

	parseTextures(pTextureRoot, pTextureIds);

	TiXmlElement* pObjectRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	parseObjects(pObjectRoot, pObjects);

	return true;
}

void StateParser::parseObjects(TiXmlElement * pStateRoot, std::vector<GameObject*>* pObjects)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackId, animSpeed;
		std::string textureId;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackId);
		e->Attribute("animSpeed", &animSpeed);
		textureId = e->Attribute("textureID");

		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureId, numFrames, callbackId, animSpeed));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement * pStateRoot, std::vector<std::string>* pTextureIds)
{
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		std::string fileNameAttr = e->Attribute("filename");
		std::string idAttr = e->Attribute("ID");
		pTextureIds->push_back(idAttr);

		TextureManager::Instance()->load(fileNameAttr, idAttr, Game::Instance()->getRenderer());
	}
}
