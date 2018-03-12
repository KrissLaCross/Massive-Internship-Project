#ifndef Renderer_H
#define Renderer_H

#include "SFML\Graphics\RenderWindow.hpp"

class Image;

class Renderer
{
public:
    bool Init();
    void Shutdown();

	void Prepare();
    void Render();
    void Draw(Image* image);

private:

	sf::RenderWindow* mySFMLWindow;
};

#endif
