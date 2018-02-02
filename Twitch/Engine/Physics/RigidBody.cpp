#include "RigidBody.h"
#include "../Engine.h"

RigidBody::RigidBody()
{
	// Expected use:
	//     velocity.y -= gravity * DT
	gravity = 0;

	// Because of how the math works out in:
	//    velocity.x *= friction
	// 0 would cause a full-stop along the specified axis,
	// which means 0 represents full friction, and 1 represents
	// no friction
	friction = 1;
}

void RigidBody::Initialize(float _gravity, float _friction, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size)
{
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void RigidBody::Update()
{
	velocity.x *= friction;
	velocity.y += gravity;

	*pos = *pos + (velocity * Engine::GetDT());
}

void RigidBody::Render(Vector3 color)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	// 2D only rotates on the Z axis
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(color.x, color.y, color.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);

		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);
	}
	glEnd();
}

void RigidBody::AddForce(Vector3 force)
{
	velocity = velocity + force;
}