#include "InputManager.h"

InputManager::InputManager(Object* _object)
{
	object = _object;
}

void InputManager::Update()
{
	if (Keyboard::Key(GLFW_KEY_W) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (clock->getCurrentSeconds() > 2) {
			object->flap();
			clock->startTimer();
		}
	}

	//Up down left right
	if (Keyboard::Key(GLFW_KEY_A))
	{
		object->GetRB().AddForce(Vector3(-75, 0, 0));
	}
	if (Keyboard::Key(GLFW_KEY_D))
	{
		object->GetRB().AddForce(Vector3(75, 0, 0));
	}

}