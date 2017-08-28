#include "InputHandler.h"
#include <iostream>
#include "Game.h"

InputHandler* InputHandler::s_pInstane = 0;

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			onKeydown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
		if (event.type == SDL_QUIT)
		{
			
		}

	}
}

void InputHandler::clean()
{
	if (m_bJoysticksInitialised)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (SDL_JoystickGetAttached(joy))
			{
				m_joysticks.push_back(joy);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;
		std::cout << "initialised " << m_joysticks.size() << " joystick(s)\n";
	}
	else
	{
		std::cout << "No joysticks connected\n";
		m_bJoysticksInitialised = false;
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystate != 0)
	{
		if (m_keystate[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}
