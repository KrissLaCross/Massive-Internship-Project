#ifndef Game_H
#define Game_H

#include "GameWindow.h"
#include "Renderer.h"
#include "EventHandler.h"
#include "InputManager.h"
#include "World.h"

#include <iostream>

class Image;

class Game
{
public:
    static bool Create();
    static Game* GetInstance();
    static void Destroy();

    bool Run();
    void Stop();

    void Update();
    void Render();

    static GameWindow* GetGameWindow();
    static Renderer* GetRenderer();
    static InputManager* GetInput();
    static World* GetWorld();

private:
    Game();
    ~Game();
    bool Init();
    bool Shutdown();

	GameWindow myGameWindow;
    Renderer myRenderer;
    EventHandler myEventHandler;
    InputManager myInputManager;

    World myWorld;

    bool myRunning;

    static Game* ourGame;
};

#endif
