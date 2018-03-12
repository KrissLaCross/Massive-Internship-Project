#ifndef ProjectileManager_H
#define ProjectileManager_H

#include "Entity.h"
#include "Vector.h"
#include "Projectile.h"


class ProjectileManager
{
public:

    void Init();
    ProjectileManager();
    void Update();
    void Draw();
    void CreateProjectile(Projectile::ProjectileType aType, Vector2f aPosition, Vector2f aDirection, Entity* shooter);

    bool GetCollidedEntity(const Entity* anEntity, Entity* aReturnEntity);
private:
    Vector<Projectile*> myProjectiles;
};

#endif