#include "Entity.h"
#include "Game.h"
#include "Renderer.h"
#include "Image.h"
#include "Settings.h"

Entity::Entity()
:myImage(0)
{
    myCollisionRadius = Settings::Collision_defaultRadius;
}

Entity::~Entity()
{
    if (myImage)
    {
        delete myImage;
	}

	SetCollisionEnabled(false);
}

void Entity::Draw()
{
    if (myImage)
    {
		myImage->SetPosition(myPos);

        Game::GetRenderer()->Draw(myImage);
    }
}

void Entity::CreateImage(const char* path, int xOffset, int yOffset, int width, int height)
{
    myImage = new Image(path, xOffset, yOffset, width, height);
}

void Entity::Update()
{

}

Vector2f Entity::GetPosition() const
{
    return myPos;
}

float Entity::GetCollisionRadius() const
{
    return myCollisionRadius;
}

void Entity::SetCollisionEnabled(bool aValue)
{
    if (aValue)
    {
        Game::GetCollision()->AddCollisionItem(this);
    }
    else
    {
        Game::GetCollision()->RemoveCollisionItem(this);
    }
}

void Entity::SetCollisionRadius(float aRadius)
{
    myCollisionRadius = aRadius;
}
