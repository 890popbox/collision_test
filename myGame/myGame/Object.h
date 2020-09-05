#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Rect.h"

class Object
{
public:
	Object();
	Object(Sprite _sprite);

	void setGravity(int x);
	void Update();
	void Render();

	void EndRender();

	void straightenOb();

	void flap();

	//Accessors
	Sprite& GetSprite();
	Rigidbody& GetRB();

private:
	Sprite sprite;
	Rigidbody rb;
	Rect boundingRect;

	float objectForce;
	float maxRot;
	float minRot;
	float straightSpot;

};

#endif