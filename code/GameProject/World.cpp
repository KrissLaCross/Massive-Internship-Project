#include "World.h"
#include "Avatar.h"
#include "Enemy.h"
#include "Image.h"
#include "Game.h"
#include "Settings.h"

void World::Create()
{
    myBackGround = new Image(Settings::Background_defaultImage);
	myBackGround->SetPosition(Vector2f(0, 0));

    myAvatar = new Avatar;
    myEnemy = new Enemy;
}

void World::Destroy()
{
    delete myAvatar;
    delete myEnemy;
    delete myBackGround;
}

void World::Update()
{
    myAvatar->Update();
    myEnemy->Update();
}

void World::Draw()
{
    //Game::GetRenderer()->Draw(myBackGround);

    //myAvatar->Draw();
    //myEnemy->Draw();
	Game::GetRenderer()->DrawLine(100, 100, 300, 200);
	Game::GetRenderer()->DrawCircle(400, 400, 32, true);
	Game::GetRenderer()->DrawRect(100, 300, 32, 32, false);

}

