#pragma once
#include <vector>
#include <SDL.h>

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstane == 0)
		{
			s_pInstane = new InputHandler();
			return s_pInstane;
		}
		return s_pInstane;
	}
	~InputHandler();

	void update();
	void clean();
	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }
	void onKeydown() { m_keystate = SDL_GetKeyboardState(0); }
	void onKeyUp() { m_keystate = SDL_GetKeyboardState(0); }
	bool isKeyDown(SDL_Scancode key);

private:
	InputHandler();
	static InputHandler* s_pInstane;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	const Uint8* m_keystate;
};
typedef InputHandler TheInputHandler;
