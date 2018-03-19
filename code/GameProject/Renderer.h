#ifndef Renderer_H
#define Renderer_H

#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\CircleShape.hpp"

class Image;

class Renderer
{
public:
    bool Init();
    void Shutdown();

	void Prepare();
    void Render();
    void Draw(Image* image);
	
	void DrawLine(float x1, float y1, float x2, float y2);
	void DrawLine(sf::Vector2f aStart, sf::Vector2f aEnd);

	void DrawRect(float x, float y, float aWidth, float aHeight, bool isCentered = false);
	void DrawRect(sf::Vector2f aPosition, sf::Vector2f aSize, bool isCentered = false);

	void DrawCircle(float x, float y, float aRadius, bool isCentered = false);
	void DrawCircle(sf::Vector2f aPosition, float aRadius, bool isCentered = false);

private:
	sf::RenderWindow* mySFMLWindow;
	sf::RectangleShape myRectangle;
	sf::CircleShape myCircle;
};

#endif
