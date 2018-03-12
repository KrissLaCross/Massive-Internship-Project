#ifndef Projectile_H
#define Projectile_H

#include "Entity.h"

class ProjectileManager;

class Projectile : public Entity
{
public:
    enum ProjectileType
    {
        e9MM,
        eNumBulletTypes
    };

    Projectile(Vector2f& aPosition, Vector2f& aDirection, ProjectileType aType, Entity* shooter);

    void Update();

    bool MarkedForDelete();

private:
    const char* GetProjectileImage(ProjectileType aType);   
    void CheckForCollisions();
    void Collide(Entity* otherEntity);

    float mySpeed;
    Vector2f myDirection;
    float myTraveledDistance;
    bool myMarkedForDelete;
    Entity* myShooter;

    ProjectileManager* myProjectileManager;
};

#endif