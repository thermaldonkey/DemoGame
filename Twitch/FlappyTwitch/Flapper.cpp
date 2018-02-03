#include "Flapper.h"

#include "../Engine/Math/Rect.h"

Flapper::Flapper()
{
	flapForce = 750;
	maxRotate = 30;
	minRotate = -maxRotate;
}

Flapper::Flapper(Sprite _sprite) : Flapper()
{
	sprite = _sprite;

	Rect boundingRect = Rect();
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale());
	rb.Initialize(-10, 0.8f, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
}

void Flapper::Update()
{
	sprite.Update();
	rb.Update();

	float yVel = rb.GetVelocity().y;
	if (flapForce == 0)
	{
		cout << "Error! Flapping will do you no good!" << endl;
		flapForce = 750;
	}
	float newRotate = yVel * (maxRotate / flapForce);
	sprite.RotateTo(newRotate);
}

void Flapper::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

void Flapper::Flap()
{
	rb.SetVelocity(Vector3(0, flapForce, 0));
	sprite.RotateTo(maxRotate);
}

Sprite& Flapper::GetSprite()
{
	return sprite;
}

RigidBody& Flapper::GetRB()
{
	return rb;
}