#ifndef GAME_INPUTMANAGER
#define GAME_INPUTMANAGER

#include "../Engine/Engine.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/Timer.h"
#include "Object.h"

class InputManager
{
public:
	Timer *clock = new Timer;
	InputManager(Object* _object);

	void Update();
private:

	Object* object;


};


#endif