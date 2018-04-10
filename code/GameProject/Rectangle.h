#ifndef HEADER_RECTANGLE
#define HEADER_RECTANGLE

#include "Vector2.h"

namespace stoffe
{
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(Vector2F aPosition, Vector2F aSize);
		Rectangle(float x, float y, Vector2F aSize);
		Rectangle(Vector2F aPosition, float aWidth, float aHeight);
		Rectangle(float x, float y, float aWidth, float aHeight);
		~Rectangle();

		inline const Vector2F& GetPosition() const { return myPosition; };
		inline const Vector2F& GetSize() const { return mySize; }

		inline const Vector2F GetTopLeft() const { return myPosition; }
		inline const Vector2F GetTopRight() const { return myPosition + mySize * Vector2F::UNITX; };
		inline const Vector2F GetBottomLeft() const { return myPosition + mySize * Vector2F::UNITY; };
		inline const Vector2F GetBottomRight() const { return myPosition + mySize; };

		inline const Vector2F Min() const { return myPosition; }
		inline const Vector2F Max() const { return myPosition + mySize; }

		inline const Vector2F GetMiddle() const { return myPosition + mySize * 0.5f; };
		Vector2F* GetCorners() const;

		void SetPosition(const Vector2F &aPosition);
		void Translate(const Vector2F &aTranslation);

		void Draw() const;

	private:
		Vector2F myPosition;
		Vector2F mySize;
	};	
}

#endif // HEADER_RECTANGLE