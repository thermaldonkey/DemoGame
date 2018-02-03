#include "RigidBody.h"
#include "../Engine.h"

#include "../Math/Math.h"

#include <vector>
using namespace std;

bool RigidBody::IsColliding(const RigidBody& rbA, const RigidBody& rbB)
{
	Rect rcA = rbA.boundingRect;
	Rect rcB = rbB.boundingRect;

	Vector3 aUR = rcA.upperRightVertex + *rbA.pos;
	Vector3 aUL = rcA.upperLeftVertex + *rbA.pos;
	Vector3 aLR = rcA.lowerRightVertex + *rbA.pos;
	Vector3 aLL = rcA.lowerLeftVertex + *rbA.pos;
	Vector3 bUR = rcB.upperRightVertex + *rbB.pos;
	Vector3 bUL = rcB.upperLeftVertex + *rbB.pos;
	Vector3 bLR = rcB.lowerRightVertex + *rbB.pos;
	Vector3 bLL = rcB.lowerLeftVertex + *rbB.pos;

	float aMax = 0;
	float aMin = 0;
	float bMax = 0;
	float bMin = 0;

	Vector3 axis1 = aUR - aUL;
	Vector3 axis2 = aUR - aLR;
	Vector3 axis3 = bUL - bLL;
	Vector3 axis4 = bUL - bUR;

	vector<Vector3> axes;
	axes.push_back(axis1);
	axes.push_back(axis2);
	axes.push_back(axis3);
	axes.push_back(axis4);

	for (int i = 0; i < axes.size(); i++)
	{
		Vector3 aURProjection = Vector3::Project(aUR, axes[i]);
		Vector3 aULProjection = Vector3::Project(aUL, axes[i]);
		Vector3 aLRProjection = Vector3::Project(aLR, axes[i]);
		Vector3 aLLProjection = Vector3::Project(aLL, axes[i]);
		Vector3 bURProjection = Vector3::Project(bUR, axes[i]);
		Vector3 bULProjection = Vector3::Project(bUL, axes[i]);
		Vector3 bLRProjection = Vector3::Project(bLR, axes[i]);
		Vector3 bLLProjection = Vector3::Project(bLL, axes[i]);

		float aURScalar = Vector3::Dot(aURProjection, axes[i]);
		float aULScalar = Vector3::Dot(aULProjection, axes[i]);
		float aLRScalar = Vector3::Dot(aLRProjection, axes[i]);
		float aLLScalar = Vector3::Dot(aLLProjection, axes[i]);
		float bURScalar = Vector3::Dot(bURProjection, axes[i]);
		float bULScalar = Vector3::Dot(bULProjection, axes[i]);
		float bLRScalar = Vector3::Dot(bLRProjection, axes[i]);
		float bLLScalar = Vector3::Dot(bLLProjection, axes[i]);

		vector<float> aScalars;
		aScalars.push_back(aURScalar);
		aScalars.push_back(aULScalar);
		aScalars.push_back(aLRScalar);
		aScalars.push_back(aLLScalar);

		aMin = Math::Min(aScalars);
		aMax = Math::Max(aScalars);

		vector<float> bScalars;
		bScalars.push_back(bURScalar);
		bScalars.push_back(bULScalar);
		bScalars.push_back(bLRScalar);
		bScalars.push_back(bLLScalar);

		bMin = Math::Min(bScalars);
		bMax = Math::Max(bScalars);

		if (!(bMin <= aMax && bMax >= aMin))
		{
			return false;
		}
	}
	return true;
}

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

void RigidBody::Initialize(float _gravity, float _friction, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect)
{
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	lastRotation = *rot;
	scale = _scale;
	size = _size;

	boundingRect = _boundingRect;
}

void RigidBody::Update()
{
	velocity.x *= friction;
	velocity.y += gravity;

	*pos = *pos + (velocity * Engine::GetDT());

	if (lastRotation != *rot)
	{
		boundingRect.lowerLeftVertex = Math::RotatePoint(boundingRect.lowerLeftVertex, Vector3(0), *rot - lastRotation);
		boundingRect.lowerRightVertex = Math::RotatePoint(boundingRect.lowerRightVertex, Vector3(0), *rot - lastRotation);
		boundingRect.upperLeftVertex = Math::RotatePoint(boundingRect.upperLeftVertex, Vector3(0), *rot - lastRotation);
		boundingRect.upperRightVertex = Math::RotatePoint(boundingRect.upperRightVertex, Vector3(0), *rot - lastRotation);
		lastRotation = *rot;
	}
}

void RigidBody::Render(Vector3 color)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);

	glColor4f(color.x, color.y, color.z, 1);
	glLineWidth(2.5);
	glBegin(GL_LINES);
	{
		glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);
		glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);

		glVertex2f(boundingRect.lowerRightVertex.x, boundingRect.lowerRightVertex.y);
		glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);

		glVertex2f(boundingRect.upperRightVertex.x, boundingRect.upperRightVertex.y);
		glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);

		glVertex2f(boundingRect.upperLeftVertex.x, boundingRect.upperLeftVertex.y);
		glVertex2f(boundingRect.lowerLeftVertex.x, boundingRect.lowerLeftVertex.y);
	}
	glEnd();
}

void RigidBody::AddForce(Vector3 force)
{
	velocity = velocity + force;
}

Vector3 RigidBody::GetVelocity()
{
	return velocity;
}

void RigidBody::SetVelocity(Vector3 _velocity)
{
	velocity = _velocity;
}