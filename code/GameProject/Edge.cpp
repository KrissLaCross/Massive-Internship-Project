#include "Edge.h"
#include "Game.h"

namespace stoffe
{
	Edge::Edge()
	{
	}

	Edge::Edge(Vector2F& aStart, Vector2F& aEnd)
		: myStart(&aStart)
		, myEnd(&aEnd)
	{
	}

	Edge::~Edge()
	{
	}

	const Vector2F& Edge::GetStart() const
	{
		return *myStart;
	}

	const Vector2F& Edge::GetEnd() const
	{
		return *myEnd;
	}

	float Edge::GetLength() const
	{
		return GetDelta().Length();
	}

	const Vector2F Edge::GetNormal() const
	{
		return GetDelta().LeftNormal();
	}

	const Vector2F Edge::GetDelta() const
	{
		return *myEnd - *myStart;
	}

	const Vector2F Edge::GetDirection() const 
	{
		return GetDelta().Normalized();
	}

	const Vector2F Edge::GetMiddle() const
	{
		return (*myStart + *myEnd) * 0.5f;
	}

	const Vector2F Edge::ClosestPointOnEdgeTo(const Vector2F &aPoint)
	{
		Vector2F fromStartToPoint = aPoint - *myStart;
		float projection = fromStartToPoint.Dot(GetDirection());
		projection = fmin(GetLength(), fmax(0.0f, projection));
		return *myStart + GetDirection() * projection;
	}

	const float Edge::ProjectOnNormal(const Vector2F & aPoint)
	{
		return GetNormal().Dot(aPoint - *myStart);
	}

	void Edge::RotateAround(float aAngle, const Vector2F & aAnchor)
	{
		myStart->RotateAround(aAngle, aAnchor);
		myEnd->RotateAround(aAngle, aAnchor);
	}

	void Edge::Draw()
	{
		Game::GetRenderer()->DrawLine(*myStart, *myEnd);
		Game::GetRenderer()->DrawLine(GetMiddle(), GetMiddle() + GetNormal() * 10.0f);
	}
}