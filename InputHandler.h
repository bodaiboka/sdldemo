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

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	void update();
	void clean();
	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }
	void onKeydown() { m_keystate = SDL_GetKeyboardState(0); }
	void onKeyUp() { m_keystate = SDL_GetKeyboardState(0); }
	bool isKeyDown(SDL_Scancode key);
	Vector2D* getMousePosition();
	bool getMouseButtonState(int buttonNumber);
	void reset();
	int getJoyXValue(int joy, int stick);
	int getJoyYValue(int joy, int stick);

private:
	const int m_joystickDeadZone = 10000;

	InputHandler();
	static InputHandler* s_pInstane;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<bool> m_mouseButtonStates;
	bool m_bJoysticksInitialised;
	const Uint8* m_keystate;
	Vector2D* m_mousePosition;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	

};
typedef InputHandler TheInputHandler;
