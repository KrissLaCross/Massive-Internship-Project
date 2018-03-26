#ifndef World_H
#define World_H

#include "Vector2.h"
#include "Edge.h"

class World
{
public:
    void Create();
    void Destroy();
    void Update();
    void Draw();

private:
	stoffe::Vector2F myCirclePos;
	stoffe::Vector2F myLineStart;
	stoffe::Vector2F myLineEnd;
	stoffe::Edge myEdge;
};

#endif
