#include "ProjectileManager.h"
#include "Projectile.h"
#include "Game.h"

ProjectileManager::ProjectileManager()
{

}

void ProjectileManager::Init()
{

}

void ProjectileManager::Update()
{
    for (size_t i = 0; i < myProjectiles.size(); ++i)
    {
        Projectile* projectile = myProjectiles[i];
        projectile->Update();
        
        if (projectile->MarkedForDelete())
        {
            myProjectiles.remove(i);
            delete projectile;
            --i;
        }
    }
}

void ProjectileManager::Draw()
{
    for (size_t i = 0; i < myProjectiles.size(); ++i)
    {
        myProjectiles[i]->Draw();
    }
}

void ProjectileManager::CreateProjectile(Projectile::ProjectileType aType, Vector2f aPosition, Vector2f aDirection, Entity* shooter)
{
    Projectile* projectile = new Projectile(aPosition, aDirection, aType, shooter);
    myProjectiles.push_back(projectile);
}

bool ProjectileManager::GetCollidedEntity(const Entity* anEntity, Entity* aReturnEntity)
{
    if (Game::GetCollision()->GetIntersectedItem(*anEntity, aReturnEntity))
    {
        return true;
    }
    aReturnEntity = nullptr;
    return false;
}
