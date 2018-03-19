#include "Renderer.h"
#include "Image.h"
#include "Game.h"

#include "SFML\Graphics\RenderWindow.hpp"


bool Renderer::Init()
{
	mySFMLWindow = Game::GetInstance()->GetGameWindow()->GetRenderWindow();

    return true;
}

void Renderer::Shutdown()
{
	mySFMLWindow = nullptr;
}

void Renderer::Draw(Image* image)
{
	mySFMLWindow->draw(image->GetSprite());
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	DrawLine(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2));
}

void Renderer::DrawLine(sf::Vector2f aStart, sf::Vector2f aEnd)
{
	sf::Vertex line[] =
	{
		sf::Vertex(aStart),
		sf::Vertex(aEnd)
	};

	mySFMLWindow->draw(line, 2, sf::PrimitiveType::Lines);
}

void Renderer::DrawRect(float x, float y, float aWidth, float aHeight, bool isCentered)
{
	myRectangle.setPosition(x, y);
	myRectangle.setSize(sf::Vector2f(aWidth, aHeight));
	if (isCentered) myRectangle.move(-aWidth / 2, -aHeight / 2);
	mySFMLWindow->draw(myRectangle);
}

void Renderer::DrawRect(sf::Vector2f aPosition, sf::Vector2f aSize, bool isCentered)
{
	DrawRect(aPosition.x, aPosition.y, aSize.x, aSize.y, isCentered);
}

void Renderer::DrawCircle(float x, float y, float aRadius, bool isCentered)
{
	myCircle.setPosition(x, y);
	myCircle.setRadius(aRadius);
	if (isCentered) myCircle.move(-aRadius, -aRadius);
	mySFMLWindow->draw(myCircle);
}

void Renderer::DrawCircle(sf::Vector2f aPosition, float aRadius, bool isCentered)
{
	DrawCircle(aPosition.x, aPosition.y, aRadius, isCentered);
}

void Renderer::Prepare()
{
	mySFMLWindow->clear();
}

void Renderer::Render()
{
	mySFMLWindow->display();
}
