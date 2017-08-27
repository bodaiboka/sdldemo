#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <vector>
#include "GameObject.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	void quit();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	Game();
	static Game* s_pInstance;
	typedef Game TheGame;
	bool m_bRunning;
	int m_currentFrame;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	const std::string CAT_TEXTURE = "cat-alpha-texture";
	std::vector<GameObject*> m_gameObjects;
};


