#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	// This function expects (0, 0) to be the top left of the screen,
	// but we set our frame up with (0, 0) at the bottom left. Need to
	// flip the y coord
	y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0)
	{
		return;
	}

	// If our action wasn't a release, and we don't have the button marked
	// as currently pressed
	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	// If our action was a release, and we had the button marked
	// as currently pressed
	if (action == GLFW_RELEASE && buttons[button] == true)
	{
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}

double Mouse::GetMouseX()
{
	return x;
}

double Mouse::GetMouseY()
{
	return y;
}

bool Mouse::ButtonDown(int button)
{
	bool temp = buttonsDown[button];
	buttonsDown[button] = false;
	return temp;
}

bool Mouse::ButtonUp(int button)
{
	bool temp = buttonsUp[button];
	buttonsUp[button] = false;
	return temp;
}

bool Mouse::Button(int button)
{
	return buttons[button];
}