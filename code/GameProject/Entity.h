#ifndef Entity_H
#define Entity_H

#include "Vector2f.h"

class Image;

class Entity
{
public:
    Entity();
    ~Entity();
    virtual void Update();
    virtual void Draw();
    Vector2f GetPosition() const;
    float GetCollisionRadius() const;

protected:
    virtual void CreateImage(const char* path, int xOffset = 0, int yOffset = 0, int width = 0, int height = 0);

    // Collision
    void SetCollisionEnabled(bool aValue);
    void SetCollisionRadius(float aRadius);

    Vector2f myPos;
    Image* myImage;
    float myCollisionRadius;
};

#endif
