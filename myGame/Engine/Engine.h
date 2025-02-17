#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib,"opengl32.lib")

#include <iostream>
using namespace std;

class Engine {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float GetDT();

	//Constructors
	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;

	static float dt;
	float lastTime;

};

#endif