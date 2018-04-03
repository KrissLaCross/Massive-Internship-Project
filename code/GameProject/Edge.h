#ifndef HEADER_EDGE
#define HEADER_EDGE

#include "Vector2.h"

namespace stoffe
{
	class Edge
	{
	public:
		Edge();
		Edge(Vector2F& aStart, Vector2F& aEnd);
		~Edge();

		const Vector2F& GetStart() const;
		const Vector2F& GetEnd() const;
		float GetLength() const;
		const Vector2F GetNormal() const;
		const Vector2F GetDelta() const;

		const Vector2F GetDirection() const;

		const Vector2F GetMiddle() const;

		const Vector2F ClosestPointOnEdgeTo(const Vector2F &aPoint);
		const float ProjectOnNormal(const Vector2F &aPoint);

		void RotateAround(float aAngle, const Vector2F &aAnchor);

		void Draw();

	private:
		Vector2F *myStart;
		Vector2F *myEnd;

	};
}

#endif // !HEADER_EDGE