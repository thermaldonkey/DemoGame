#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;

// Handles the scaling, rotating, and rendering of a specific texture
class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	// Because we're 2D, we assume all rotations will be along the Z axis.
	// This sets absolute rotation
	void RotateTo(float x);
	// This sets relative rotation
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;

	float speed;

	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;
};
#endif