#ifndef Enemy_H
#define Enemy_H

#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy();
    ~Enemy();

    virtual void Update();
};

#endif
