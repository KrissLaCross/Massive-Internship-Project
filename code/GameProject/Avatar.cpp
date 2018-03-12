#include "Avatar.h"
#include "Image.h"
#include "Game.h"
#include "Timer.h"
#include "ProjectileManager.h"
#include "Settings.h"

Avatar::Avatar()
:Entity()
{
    CreateImage(Settings::Avatar_defaultImage, 32, 0, 32, 32);
    myPos.Set(100.0f,100.0f);
    m_input = Game::GetInput();
    SetCollisionRadius(30.0f);
}

Avatar::~Avatar()
{
}

void Avatar::Update()
{
    Move();

    if (m_input->WasButtonPressed(InputManager::eFire))
    {
        Shoot();
    }
}

void Avatar::Move()
{
    float delta = Timer::GetElapsedFrameTime();
    float speed = Settings::Avatar_defaultSpeed;

    if (m_input->IsButtonDown(InputManager::eMoveLeft))
    {
        myPos.x -= speed * delta;
    }
    if (m_input->IsButtonDown(InputManager::eMoveRight))
    {
        myPos.x += speed * delta;
    }
    if (m_input->IsButtonDown(InputManager::eMoveUp))
    {
        myPos.y -= speed * delta;
    }
    if (m_input->IsButtonDown(InputManager::eMoveDown))
    {
        myPos.y += speed * delta;
    }
}

void Avatar::Shoot()
{
    Vector2f cursor;
    m_input->GetCursorPosition(cursor.x, cursor.y);

    Vector2f dir;
    dir.Set(cursor.x - myPos.x, cursor.y - myPos.y);
    
    Game::GetProjectiles()->CreateProjectile(Projectile::e9MM, myPos, dir, this);
}
