#include "Mouse.h"

//vertexs
double Mouse::x = 0;
double Mouse::y = 0;

//Setting up mouse buttons
bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{ //If button isn't pressed
	if (button < 0)
		return;

	//Check if anything happens
	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}
	if (action != GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}

//Get mouse spots..

double Mouse::GetMouseX()
{
	return x;
}

double Mouse::GetMouseY()
{
	return y;
}

//Return stuff

bool Mouse::ButtonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}

bool Mouse::ButtonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Mouse::Button(int button)
{
	return buttons[button];
}