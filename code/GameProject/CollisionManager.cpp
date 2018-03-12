#include "CollisionManager.h"
#include "Entity.h"

void CollisionManager::AddCollisionItem(Entity* anItem)
{
    myCollisionItems.push_back(anItem);
}

void CollisionManager::RemoveCollisionItem(Entity* anItem)
{
    myCollisionItems.removeitem(anItem);
}

bool CollisionManager::GetIntersectedItem(const Entity& anItem, Entity* aReturnHit)
{
    for (size_t i = 0; i < myCollisionItems.size(); ++i)
    {
        if (&anItem != myCollisionItems[i] && CheckIntersection(anItem, *myCollisionItems[i]))
        {
            aReturnHit = myCollisionItems[i];
            return true;
        }
    }

    return false;
}

bool CollisionManager::CheckIntersection(const Entity& anItem, const Entity& anotherItem)
{
    Vector2f position1 = anItem.GetPosition();
    Vector2f position2 = anotherItem.GetPosition();
    if ( (position2 - position1).Length() < anItem.GetCollisionRadius() + anotherItem.GetCollisionRadius() )
    {
        return true;
    }

    return false;
}
