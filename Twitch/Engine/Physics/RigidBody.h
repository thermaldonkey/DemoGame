#ifndef TWITCH_RIGIDBODY
#define TWITCH_RIGIDBODY

#include "../Math/Vector3.h"
#include "../Math/Rect.h"

// Works with the sprite to handle all math involved with changing
// the sprite's positioning (so the sprite doesn't need to care
// about that stuff)
class RigidBody
{
public:

	static bool IsColliding(const RigidBody& rbA, const RigidBody& rbB);

	RigidBody();

	void Initialize(float _gravity, float _friction, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect);

	void Update();
	// This is just for debugging. In-game, the sprite will handle rendering
	void Render(Vector3 color);

	void AddForce(Vector3 force);
	Vector3 GetVelocity();
	void SetVelocity(Vector3 _velocity);

private:
	Vector3* pos;
	float* rot;
	float lastRotation;
	Vector3* scale;
	Vector3* size;

	float gravity;
	float friction;
	Vector3 velocity;

	Rect boundingRect;
};

#endif