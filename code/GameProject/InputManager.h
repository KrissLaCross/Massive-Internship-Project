#ifndef InputManager_H
#define InputManager_H

#include "Vector2.h"

class InputManager
{
public:
    struct ButtonState
    {
        bool isDown;
        bool wasDown;
    };


	enum Button
    {
        eMoveUp,
        eMoveDown,
        eMoveLeft,
        eMoveRight,
        
		eFire,
		eMouseLeft,
		eMouseRight,

		eEscape,

        eTOTAL_SIZE
    };

    void Init();

    void Update();

    bool IsButtonDown(Button button);
    bool WasButtonPressed(Button button);
    
	bool WasMouseHit(Button button);
	bool IsMouseDown(Button button);
	bool WasMouseReleased(Button button);

	void GetCursorPosition(float& X, float& Y);
	stoffe::Vector2F GetCursorPosition();

private:
	void UpdateButtonStates();
	void UpdateCursorPosition();

    ButtonState myButtons[eTOTAL_SIZE];

    stoffe::Vector2F myCursorPos;
};

#endif
