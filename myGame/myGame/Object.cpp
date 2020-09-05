#include "Object.h"

#include "../Engine/Engine.h"

Object::Object() {
	//Create Object
	objectForce = 1000;
	maxRot = 5;
	minRot = -maxRot;

}

//Create it..
Object::Object(Sprite _sprite) : Object()
{
	sprite = _sprite;

	Rect BoundingRect = Rect();
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale());
	rb.Initialize(0.8f, -10, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
	straightSpot = *sprite.GetRot();
}

void Object::setGravity(int x)
{

}

void Object::Update()
{
	sprite.Update();
	rb.Update();

	float yVel = rb.GetVal().y;
	if (objectForce == 0) {
		cout << "Error, force is bad.. reseting to 1000" << endl;
		objectForce = 1000;
	}
	float newRot = (maxRot / objectForce) * yVel;
	if(newRot > straightSpot) //Min amount to rotate
		sprite.RotateTo(newRot);
}

void Object::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

void Object::EndRender() {
	sprite.EndRender();

}

void Object::straightenOb() {
	sprite.RotateTo(straightSpot);
}

//Flap..

void Object::flap()
{
	Vector3 vel = rb.GetVal();
	rb.SetVel(Vector3(vel.x, objectForce, vel.z));
	sprite.RotateTo(maxRot);
}

//Getters

Sprite& Object::GetSprite()
{
	return sprite;
}

Rigidbody& Object::GetRB()
{
	return rb;
}

