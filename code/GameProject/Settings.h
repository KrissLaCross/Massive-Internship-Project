#ifndef Settings_H
#define Settings_H

namespace Settings
{
    //Projectiles
    static const float Projectile_maxTravelDistance = 2000.0f;
    static const float Projectile_defaultSpeed = 800.0f;
    static const char* Projectile_defaultImage = "shuriken.png";

    static const char* Projectile_9MM_Image = Projectile_defaultImage;


    // Avatar
    static const float Avatar_defaultSpeed = 150.0f;
    static const char* Avatar_defaultImage = "ninjas.png";


    // Collision
    static const float Collision_defaultRadius = 10.0f;


    // Enemies
    static const char* Enemy_defaultImage = "ninjas.png";

	// Background
	static const char* Background_defaultImage = "grass.jpg";
}

#endif
