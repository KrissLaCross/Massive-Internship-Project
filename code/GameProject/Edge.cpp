#include "Edge.h"
#include "Game.h"

namespace stoffe
{
	Edge::Edge()
	{
	}

	Edge::Edge(Vector2F *aStart, Vector2F *aEnd)
		: myStart(aStart)
		, myEnd(aEnd)
	{
		Vector2F delta = *myEnd - *myStart;
		myLength = delta.Length();
		myNormal = delta.LeftNormal();
	}

	Edge::~Edge()
	{
		delete myStart;
		delete myEnd;
	}

	inline Vector2F Edge::GetStart()
	{
		return myStart;
	}

	inline Vector2F Edge::GetEnd()
	{
		return myEnd;
	}

	inline float Edge::GetLength()
	{
		return myLength;
	}

	inline Vector2F Edge::GetNormal()
	{
		return myNormal;
	}

	void Edge::Draw()
	{
		Game::GetRenderer()->DrawLine(*myStart, *myEnd);
	}
}