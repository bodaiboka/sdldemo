#pragma once
#include <iostream>
#include <vector>
#include "tinyxml\tinyxml.h"
#include "GameObject.h"

class StateParser
{
public:
	StateParser();
	~StateParser();

	bool parseState(const char* stateFile, std::string stateId, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIds);

private:
	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects);
	void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIds);

};

