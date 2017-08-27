#pragma once
#include <SDL.h>
#include <iostream>
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
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRect;
	SDL_Rect m_destinationRect;

};


