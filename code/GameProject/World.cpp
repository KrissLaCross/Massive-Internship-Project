#include "World.h"
#include "Game.h"
#include "Settings.h"
#include "Timer.h"
#include <math.h>

#include <iostream>

#define CLAMP(x, min, max) fmin(max, fmax(min, x))

bool RayCast(stoffe::Rectangle aRect, const stoffe::Vector2F& p1, const stoffe::Vector2F& p2, float& maxFraction, float& minFraction)
{
	stoffe::Vector2F d = p2 - p1;

	float lower = 0.0f;
	float upper = 1.0f;

	// Solve segment to slab plane.
	// s = p1 + w * d
	// Slab plane equation:
	// dot(n[i], s) = offset[i]
	// Solution:
	// dot(n[i], p1 + w * d) = offset[i]
	// dot(n[i], p1) + w * dot(n[i], d) = offset[i]
	// w * dot(n[i], d) = offset[i] - dot(n[i], p1)
	// w = (offset[i] - dot(n[i], p1)) / dot(n[i], d)

	for (unsigned short i = 0; i < 2; ++i)
	{
		// Evaluate equations for the near and far plane of the current axis.
		float numerators[2], denominators[2];
		// Note the negative signs used as dot products.
		// The sign (-m_lower[i]) below is for because is the
		// plane offset along the plane normal
		// and not aways along the positive axis!
		// We're basically evaluating the plane equation
		// for any corner on this near plane
		// (e.g. dot(corner[i], normal[i]) = offset).

		numerators[0] = (-aRect.Min()[i]) - (-p1[i]);
		numerators[1] = (aRect.Max()[i]) - (p1[i]);
		denominators[0] = -d[i];
		denominators[1] = d[i];

		// For each plane...
		for (unsigned short j = 0; j < 2; ++j)
		{
			float numerator = numerators[j];
			float denominator = denominators[j];

			if (denominator == 0.0f)
			{
				// s is parallel to this half-space.
				if (numerator < 0.0f)
				{
					// s is outside of this half-space.
					// dot(n, p1) and dot(n, p2) &amp;lt; 0 is guaranteed.
					return false;
				}
			}
			else
			{
				float fraction = numerator / denominator;
				if (denominator < 0.0f)
				{
					// s enters this half-space.
					if (fraction > lower)
					{
						// Increase lower.
						lower = fraction;
					}
				}
				else
				{
					// s exits the half-space.
					if (fraction < upper)
					{
						// Decrease upper.
						upper = fraction;
					}
				}
				// Exit if intersection becomes empty.
				if (upper < lower)
				{
					return false;
				}
			}
		}
	}

	// Output minimum intersection fraction.
	// You must evaluate the segment equation to get the closest point on the bounds.
	minFraction = lower;
	maxFraction = upper;

	return true;
}

void World::Create()
{
	myLineStart = { 256 + 64, 256 };
	myLineEnd = { 256 - 64, 256 };
	myEdge = { myLineStart, myLineEnd };
	myRectangle = stoffe::Rectangle({ 256 - 32, 256 + 96 }, { 64, 64 });
	myEdge.RotateAround(0.1f, myEdge.GetMiddle());
}

void World::Destroy()
{

}

void World::Update()
{
	stoffe::Vector2F dir;
	dir.x = Game::GetInput()->IsButtonDown(InputManager::eMoveRight) - Game::GetInput()->IsButtonDown(InputManager::eMoveLeft);
	dir.y = Game::GetInput()->IsButtonDown(InputManager::eMoveDown) - Game::GetInput()->IsButtonDown(InputManager::eMoveUp);
	stoffe::Vector2F vel = dir * Timer::GetElapsedFrameTime() * 64.0f;


	stoffe::Vector2F outnorm = stoffe::Vector2F::ZERO;
	stoffe::Vector2F outvel = outnorm;


	myRectangle.Translate(vel);


}

void World::Draw()
{


	myEdge.Draw();
	myRectangle.Draw();

	float min = 0.0f;
	float max = 1.0f;
	myHit = RayCast(myRectangle, myEdge.GetStart(), myEdge.GetEnd(), max, min);

	if (myHit)
	{
		if (min == 0.0f)
		{

		}
		else if (max == 1.0f)
		{

		}
		else
		{
			float minProjection = INFINITY;

			for (unsigned short i = 0; i < 4; i++)
			{
				float dot = myEdge.ProjectOnNormal(myRectangle.GetCorners()[i]);
				minProjection = fmin(minProjection, dot);
			}

			myRectangle.Translate(-myEdge.GetNormal() * minProjection);
		}


		Game::GetRenderer()->DrawCircle(myEdge.GetStart() + myEdge.GetDelta() * min, 4, true);
		Game::GetRenderer()->DrawCircle(myEdge.GetStart() + myEdge.GetDelta() * max, 4, true);
		Game::GetRenderer()->DrawRect({ 20, 20 }, { 20, 20 });
	}

}

