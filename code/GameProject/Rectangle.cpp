#include "Rectangle.h"
#include "Game.h"

namespace stoffe
{
	Rectangle::Rectangle()
	{
	}

	Rectangle::Rectangle(Vector2F aPosition, Vector2F aSize)
		: myPosition(aPosition)
		, mySize(aSize)
	{
	}

	Rectangle::Rectangle(float x, float y, Vector2F aSize)
		: myPosition({ x, y })
		, mySize(aSize)
	{
	}

	Rectangle::Rectangle(Vector2F aPosition, float aWidth, float aHeight)
		: myPosition(aPosition)
		, mySize({ aWidth, aHeight })
	{
	}

	Rectangle::Rectangle(float x, float y, float aWidth, float aHeight)
		: myPosition({ x, y })
		, mySize({ aWidth, aHeight })
	{
	}

	Rectangle::~Rectangle()
	{
	}

	Vector2F * Rectangle::GetCorners() const
	{
		// Vector2F *corners = new Vector2F[4]; MEMORY LEAK. HEAP ALLOCATED MEMORY THAT NEVER GETS DELETED. 
		static Vector2F corners[4]; // Needs to be static, else we lose the values when the scope is poped from the stack.
		corners[0] = GetTopLeft();
		corners[1] = GetTopRight();
		corners[2] = GetBottomRight();
		corners[3] = GetBottomLeft();
		return corners;
	}

	void Rectangle::SetPosition(const Vector2F & aPosition)
	{
		myPosition = aPosition;
	}

	void Rectangle::Translate(const Vector2F & aTranslation)
	{
		myPosition += aTranslation;
	}

	void Rectangle::Draw() const
	{
		Vector2F *corners = GetCorners();

		for (unsigned short i = 0; i < 4; i++)
		{
			Game::GetRenderer()->DrawLine(corners[i], corners[(i + 1) % 4]);
		}

		corners = nullptr;
	}
}