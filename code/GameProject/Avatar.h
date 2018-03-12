#ifndef Avatar_H
#define Avatar_H

#include "Entity.h"

class InputManager;

class Avatar : public Entity
{
public:
    Avatar();
    ~Avatar();
    
    void Update();

private:
    void Move();
    void Shoot();

    InputManager* m_input;
};

#endif