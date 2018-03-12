#ifndef Game_H
#define Game_H

#include "GameWindow.h"
#include "Renderer.h"
#include "EventHandler.h"
#include "InputManager.h"
#include "World.h"
#include "ProjectileManager.h"
#include "CollisionManager.h"

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
    static ProjectileManager* GetProjectiles();
    static World* GetWorld();
    static CollisionManager* GetCollision();

private:
    Game();
    ~Game();
    bool Init();
    bool Shutdown();

	GameWindow myGameWindow;
    Renderer myRenderer;
    EventHandler myEventHandler;
    InputManager myInputManager;
    ProjectileManager myProjectileManager;
    CollisionManager myCollisionManager;

    World myWorld;

    bool myRunning;

    static Game* ourGame;
};

#endif
