#ifndef TWITCH_MOUSE
#define TWITCH_MOUSE

#include "GLFW/glfw3.h"

class Mouse
{
public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static double GetMouseX();
	static double GetMouseY();

	// Was the given button just pressed?
	static bool ButtonDown(int button);
	// Was the given button just released?
	static bool ButtonUp(int button);
	// Is the button currently pressed?
	static bool Button(int button);

private:
	static double x;
	static double y;

	// All buttons available
	static bool buttons[];
	// All buttons that are pressed down
	static bool buttonsDown[];
	// All buttons that are released
	static bool buttonsUp[];
};

#endif