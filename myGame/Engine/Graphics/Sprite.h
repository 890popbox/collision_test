#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);
	//Update image..
	void setTexture(string imagePath);
	//Update and render
	void Update();
	void Render();
	void EndRender();
	//Speed of object
	void SpeedTo(float x);
	void SpeedBy(float x);
	//Moving
	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);
	//More movement
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	//Rotating
	void RotateTo(float x);
	void RotateBy(float x);
	//Scale..
	void SetScale(float x);
	void SetScale(Vector3 v);
	
	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();


private:
	Texture texture;

	float speed;
	//Using vec3 for maths
	Vector3 pos;
	float rot;
	Vector3 scale;
	Vector3 size;

};





#endif