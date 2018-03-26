#ifndef HEADER_EDGE
#define HEADER_EDGE

#include "Vector2.h"

namespace stoffe
{
	class Edge
	{
	public:
		Edge();
		Edge(Vector2F *aStart, Vector2F *aEnd);
		~Edge();

		inline Vector2F GetStart();
		inline Vector2F GetEnd();
		float GetLength();
		inline Vector2F GetNormal();

		void Draw();

	private:
		Vector2F* myStart;
		Vector2F* myEnd;
		float myLength;
		Vector2F myNormal;

	};
}

#endif // !HEADER_EDGE