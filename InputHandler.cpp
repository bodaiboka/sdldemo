#include <iostream>
#include "Game.h"
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstane = 0;

InputHandler::InputHandler()
{
	m_mousePosition = new Vector2D(0,0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

int InputHandler::getJoyXValue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getX();
		}
	}
	return 0;
}

int InputHandler::getJoyYValue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getY();
		}
	}
	return 0;
}


InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		int whichOne = event.jaxis.which;
		switch (event.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		case SDL_JOYAXISMOTION:
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setX(0);
				}
			}
			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setY(0);
				}
			}
			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setX(0);
				}
			}
			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setY(0);
				}
			}
			break;
		case SDL_KEYDOWN:
			onKeydown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
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
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
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

Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

void InputHandler::reset()
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}
