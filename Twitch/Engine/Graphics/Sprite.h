#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xPos, float _yPos);

	void Update();
	void Render();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

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
	void SetScale(float x, float y);

private:
	Texture texture;

	float speed;

	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;
};
#endif