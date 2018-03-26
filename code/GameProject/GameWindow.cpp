#include "GameWindow.h"

GameWindow::GameWindow()
	:mySFMLWindow(sf::VideoMode(512, 512), "SFML works!", sf::Style::Default, sf::ContextSettings(0U, 0U, 16U))
{

}

bool GameWindow::PollEvent(Event& outEvent)
{
	sf::Event event;
	mySFMLWindow.pollEvent(event);

	if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
	{
		outEvent = CLOSE;
		return true;
	}

	return false;
}

sf::RenderWindow* GameWindow::GetRenderWindow()
{
	return &mySFMLWindow;
}