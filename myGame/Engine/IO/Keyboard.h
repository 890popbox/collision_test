#ifndef GAME_KEYBOARD
#define GAME_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
public:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	//Key stuff..
	static bool KeyDown(int key);
	static bool KeyUp(int key);
	static bool Key(int key);

private:
	//Array of keys..
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];



};

#endif