#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"
using namespace std;

class Game
{
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return m_bRunning; }

private:
	bool m_bRunning;
	int m_currentFrame;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	TextureManager m_TextureManager;
	const std::string CAT_TEXTURE = "cat-alpha-texture";
};


