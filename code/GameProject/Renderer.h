#ifndef Renderer_H
#define Renderer_H

#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\CircleShape.hpp"
#include "Vector2.h"

class Image;

class Renderer
{
public:
    bool Init();
    void Shutdown();
	
	void Prepare();
    void Render();
	
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawLine(stoffe::Vector2F aStart, stoffe::Vector2F aEnd);

	void DrawRect(float x, float y, float aWidth, float aHeight, bool isCentered = false);
	void DrawRect(stoffe::Vector2F aPosition, stoffe::Vector2F aSize, bool isCentered = false);

	void DrawCircle(float x, float y, float aRadius, bool isCentered = false);
	void DrawCircle(stoffe::Vector2F aPosition, float aRadius, bool isCentered = false);

private:
	sf::RenderWindow* mySFMLWindow;
	sf::RectangleShape myRectangle;
	sf::CircleShape myCircle;
};

#endif
