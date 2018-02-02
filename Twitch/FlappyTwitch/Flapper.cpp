#include "Flapper.h"

Flapper::Flapper()
{

}

Flapper::Flapper(Sprite _sprite)
{
	sprite = _sprite;
	rb.Initialize(-10, 0.8f, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}

void Flapper::Update()
{
	sprite.Update();
	rb.Update();
}

void Flapper::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

Sprite& Flapper::GetSprite()
{
	return sprite;
}

RigidBody& Flapper::GetRB()
{
	return rb;
}