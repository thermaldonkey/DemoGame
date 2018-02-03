#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"

class Flapper
{
public:

	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();

	void Flap();

	Sprite& GetSprite();
	RigidBody& GetRB();

private:
	Sprite sprite;
	RigidBody rb;

	float flapForce;
	float maxRotate;
	float minRotate;
};

#endif
