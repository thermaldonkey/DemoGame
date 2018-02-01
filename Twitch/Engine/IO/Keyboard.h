#ifndef TWITCH_KEYBOARD
#define TWITCH_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	// Was the key just pressed?
	static bool KeyDown(int key);
	// Was the key just released?
	static bool KeyUp(int key);
	// Is the key currently pressed?
	static bool Key(int key);

private:
	// All keys that are currently pressed
	static bool keys[];
	// All keys that were just pressed
	static bool keysDown[];
	// All keys that were just released
	static bool keysUp[];
};
#endif