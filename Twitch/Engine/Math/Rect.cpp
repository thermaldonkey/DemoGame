#include "Rect.h"

#include <sstream>

Rect::Rect()
{
	pos = Vector3(0);
	size = Vector3(0);
	UpdateVertices();
}

Rect::Rect(Vector3 _size) : Rect()
{
	size = _size;
	UpdateVertices();
}

Rect::Rect(Vector3 _pos, Vector3 _size) : Rect(_size)
{
	pos = _pos;
	UpdateVertices();
}

void Rect::MoveBy(Vector3 by)
{
	pos = pos + by;
	UpdateVertices();
}

void Rect::MoveTo(Vector3 to)
{
	pos = to;
	UpdateVertices();
}

void Rect::SetSize(Vector3 _size)
{
	size = _size;
	UpdateVertices();
}

void Rect::UpdateVertices()
{
	// pos is based in the center of the object, so we calculate vertices by half
	// the full width and height from that point
	lowerLeftVertex		= Vector3(pos.x - (size.x / 2), pos.y - (size.y / 2), 0);
	lowerRightVertex	= Vector3(pos.x + (size.x / 2), pos.y - (size.y / 2), 0);
	upperLeftVertex		= Vector3(pos.x - (size.x / 2), pos.y + (size.y / 2), 0);
	upperRightVertex	= Vector3(pos.x + (size.x / 2), pos.y + (size.y / 2), 0);
}

string Rect::ToString()
{
	stringstream ss;
	ss << "Pos(" << pos.x << ", " << pos.y << ", " << pos.z << ") - Size(" << size.x << ", " << size.y << ", " << size.z << ")";
	return ss.str();
}