#ifndef CollisionManager_H
#define CollisionManager_H

#include "Vector.h"

class Entity;

class CollisionManager
{
public:
    void AddCollisionItem(Entity* anItem);
    void RemoveCollisionItem(Entity* anItem);

    bool GetIntersectedItem(const Entity& anItem, Entity* aReturnHit);

private:
    bool CheckIntersection(const Entity& anItem, const Entity& anotherItem);

    Vector<Entity*> myCollisionItems;
};

#endif
