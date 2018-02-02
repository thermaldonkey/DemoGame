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

	Sprite& GetSprite();
	RigidBody& GetRB();

private:
	Sprite sprite;
	RigidBody rb;
};

#endif
