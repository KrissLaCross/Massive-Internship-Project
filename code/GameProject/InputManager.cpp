#include "InputManager.h"

#include "Game.h"
#include "GameWindow.h"

#include "SFML\Window\Keyboard.hpp"
#include "SFML\Window\Mouse.hpp"
#include "SFML\Window.hpp"

void InputManager::Init()
{
    for (int i = 0; i < eTOTAL_SIZE; ++i)
    {
        myButtons[i].isDown = false;
        myButtons[i].wasDown = false;
    }
}

void InputManager::Update()
{
    for (int i = 0; i < eTOTAL_SIZE; ++i)
    {
        myButtons[i].wasDown = myButtons[i].isDown;
    }

	UpdateButtonStates();
	UpdateCursorPosition();
}

bool InputManager::IsButtonDown(Button button)
{
    if (button >= eTOTAL_SIZE || button < 0)
    {
        return false;
    }

    return myButtons[button].isDown;
}

bool InputManager::WasButtonPressed(Button button)
{
    if (button >= eTOTAL_SIZE || button < 0)
    {
        return false;
    }

    return myButtons[button].isDown && !myButtons[button].wasDown;
}

bool InputManager::WasMouseHit(Button button)
{
	if (button < eMouseLeft || button > eMouseRight)
	{
		return false;
	}

	return myButtons[button].isDown && !myButtons[button].wasDown;
}

bool InputManager::IsMouseDown(Button button)
{
	if (button < eMouseLeft || button > eMouseRight)
	{
		return false;
	}

	return myButtons[button].isDown;
}

bool InputManager::WasMouseReleased(Button button)
{

	if (button < eMouseLeft || button > eMouseRight)
	{
		return false;
	}

	return !myButtons[button].isDown && myButtons[button].wasDown;
}

void InputManager::UpdateButtonStates()
{
	if (!Game::GetGameWindow()->GetRenderWindow()->hasFocus())
		return;

	myButtons[eUp].isDown			= sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	myButtons[eDown].isDown			= sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	myButtons[eLeft].isDown			= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	myButtons[eRight].isDown		= sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	myButtons[eMoveUp].isDown		= sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	myButtons[eMoveDown].isDown		= sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	myButtons[eMoveLeft].isDown		= sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	myButtons[eMoveRight].isDown	= sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	myButtons[eMouseLeft].isDown	= sf::Mouse::isButtonPressed(sf::Mouse::Left);
	myButtons[eMouseRight].isDown	= sf::Mouse::isButtonPressed(sf::Mouse::Right);

	myButtons[eEscape].isDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

void InputManager::UpdateCursorPosition()
{
	myCursorPos = sf::Mouse::getPosition(*Game::GetGameWindow()->GetRenderWindow());
}

void InputManager::GetCursorPosition(float& X, float& Y)
{
    X = myCursorPos.x;
    Y = myCursorPos.y;
}

stoffe::Vector2F InputManager::GetCursorPosition()
{
	return myCursorPos;
}
