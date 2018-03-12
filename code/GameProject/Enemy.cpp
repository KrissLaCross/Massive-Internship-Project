#include "Enemy.h"
#include "Settings.h"

Enemy::Enemy()
{
    CreateImage(Settings::Enemy_defaultImage, 128, 0, 32, 32);
    myPos.Set(300.0f, 300.0f);
    SetCollisionEnabled(true);
	SetCollisionRadius(30.0f);
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
    Entity::Update();
}
