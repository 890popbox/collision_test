#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;
float Engine::dt = 0;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::Initialize(const char* windowTitle) {
	//If it's false..
	if (!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;
		return false;
	}
	//Create the window
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}
	//OpenGL Setup.. Anything we do occurs on our window, modified by gl
	glfwMakeContextCurrent(window);
	int width, height;
	//These values should match, swap buffers to get less flicking..
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	//Set up postion Callback..
	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	//Find the window and set it's postion
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);
	//GL Setup, Viewport..
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);
	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = (float)glfwGetTime();

	return true;
}

void Engine::Update(){ //Update Events
	float now = (float)glfwGetTime();
	dt = (now - lastTime);
	lastTime = now;
	glfwPollEvents();
}

void Engine::BeginRender() {
	glClearColor(0.5, 0.5, 0.5, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//This is where you draw to the game..
}


void Engine::EndRender() {
	//Swap buffers..
	glfwSwapBuffers(window);
}

float Engine::GetDT() {
	return dt;
}