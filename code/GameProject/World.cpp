#include "World.h"
#include "Game.h"
#include "Settings.h"
#include "Timer.h"
#include <math.h>

#include <iostream>

#define CLAMP(x, min, max) fmin(max, fmax(min, x)) 

void World::Create()
{
	myLineStart = { 256 + 64, 256 };
	myLineEnd = { 256 - 64, 256};
	myEdge = { myLineStart, myLineEnd };
	myRectangle = stoffe::Rectangle({ 256 - 32, 256 + 96}, { 64, 64 });
}

void World::Destroy()
{

}

void World::Update()
{
	stoffe::Vector2F dir;
	dir.x = Game::GetInput()->IsButtonDown(InputManager::eMoveRight) - Game::GetInput()->IsButtonDown(InputManager::eMoveLeft);
	dir.y = Game::GetInput()->IsButtonDown(InputManager::eMoveDown) - Game::GetInput()->IsButtonDown(InputManager::eMoveUp);
	myRectangle.Translate(dir * Timer::GetElapsedFrameTime() * 32.0f);

	myEdge.RotateAround((Game::GetInput()->IsButtonDown(InputManager::eRight) - Game::GetInput()->IsButtonDown(InputManager::eLeft)) * Timer::GetElapsedFrameTime() , myEdge.GetMiddle());
}

void World::Draw()
{
	stoffe::Vector2F *corners = myRectangle.GetCorners();
	float minProjection = INFINITY;

	for (unsigned short i = 0; i < 4; i++)
	{
		float dot = myEdge.ProjectOnNormal(corners[i]);
		minProjection = fmin(minProjection, dot);
		Game::GetRenderer()->DrawLine(myEdge.GetMiddle(), myEdge.GetMiddle() + myEdge.GetNormal() * dot);
	}

	if (minProjection < 0) myRectangle.Translate(-myEdge.GetNormal() * minProjection);

	myEdge.Draw();
	myRectangle.Draw();

}

