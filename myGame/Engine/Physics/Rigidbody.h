#ifndef GAME_RIGID_BODY
#define GAME_RIGID_BODY

#include "../Math/Vector3.h"
#include "../Math/Rect.h"

class Rigidbody
{
public:
	static bool IsColliding(const Rigidbody& rbA, const Rigidbody &rbB);

	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect);
	//Game mechs
	void Update();
	void Render(Vector3 c);

	void setGravity(float x);

	void AddForce(Vector3 f);
	void SetVel(Vector3 _vel);
	Vector3 GetVal();

private:
	Vector3* pos;
	float* rot;
	float lastRot;
	Vector3* scale;
	Vector3* size;

	//Pysics
	float gravity;
	float friction;
	Vector3 vel;

	Rect boundingRect;
};

#endif