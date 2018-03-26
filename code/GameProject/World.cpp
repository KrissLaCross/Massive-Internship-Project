#include "World.h"
#include "Game.h"
#include "Settings.h"
#include "Timer.h"
#include <math.h>

#include <iostream>

void World::Create()
{
	myCirclePos = { 100, 400 };
	myLineStart = { 100, 100 };
	myLineEnd = { 300, 200 };
	myEdge = { &myLineStart, &myLineEnd };

}

void World::Destroy()
{

}

void World::Update()
{
	stoffe::Vector2F dir;
	dir.x = (float)Game::GetInput()->IsButtonDown(InputManager::eMoveRight) - Game::GetInput()->IsButtonDown(InputManager::eMoveLeft);
	dir.y = (float)Game::GetInput()->IsButtonDown(InputManager::eMoveDown) - Game::GetInput()->IsButtonDown(InputManager::eMoveUp);

}

void World::Draw()
{


	Game::GetRenderer()->DrawCircle(myCirclePos, 16, true);
	myEdge.Draw();
	//Game::GetRenderer()->DrawCircle(400, 400, 32, true);
	//Game::GetRenderer()->DrawRect(100, 300, 32, 32, false);

}

