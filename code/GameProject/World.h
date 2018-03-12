#ifndef World_H
#define World_H

class Image;
class Avatar;
class Enemy;

class World
{
public:
    void Create();
    void Destroy();
    void Update();
    void Draw();

private:
    Image* myBackGround;
    Avatar* myAvatar;
    Enemy* myEnemy;
};

#endif
