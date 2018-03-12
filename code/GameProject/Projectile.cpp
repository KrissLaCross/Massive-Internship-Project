#include "Projectile.h"
#include "Timer.h"
#include "Settings.h"
#include "Game.h"

Projectile::Projectile(Vector2f& aPosition, Vector2f& aDirection, ProjectileType aType, Entity* aShooter)
:mySpeed(Settings::Projectile_defaultSpeed)
,myDirection(aDirection)
,myTraveledDistance(0.0f)
,myMarkedForDelete(false)
,myShooter(aShooter)
,myProjectileManager(Game::GetProjectiles())
{
    CreateImage(GetProjectileImage(aType));
    myDirection.Normalize();

    myPos.Set(aPosition.x, aPosition.y);

    SetCollisionRadius(3.0f);
    SetCollisionEnabled(true);
}

void Projectile::Update()
{
    Entity::Update();

    float delta = Timer::GetElapsedFrameTime();

    Vector2f deltaPos(myDirection.x * mySpeed * delta, myDirection.y * mySpeed * delta);

    myPos.x += deltaPos.x;
    myPos.y += deltaPos.y;

    CheckForCollisions();

    myTraveledDistance += deltaPos.Length();
    if (myTraveledDistance > Settings::Projectile_maxTravelDistance)
        myMarkedForDelete = true;
}

bool Projectile::MarkedForDelete()
{
    return myMarkedForDelete;
}

void Projectile::CheckForCollisions()
{
    Entity* returnEntity = nullptr;    
    if (myProjectileManager->GetCollidedEntity(this, returnEntity))
    {
		Collide(returnEntity);
		myMarkedForDelete = true;
    }
}

void Projectile::Collide(Entity* otherEntity)
{
    std::cout << "Collision at position (" << myPos.x << ", " << myPos.y << ")." << std::endl;
}

const char* Projectile::GetProjectileImage(ProjectileType aType)
{
    switch (aType)
    {
    case e9MM:
        return Settings::Projectile_9MM_Image;
    default:
        return Settings::Projectile_defaultImage;
    }
}
