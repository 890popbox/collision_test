#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
	pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(0);
	speed = 200;
	texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(),1);
	rot = 0;
	speed = 200;
}

Sprite::Sprite(string imagePath, Vector3 v)
{
	texture = Texture(imagePath);
	pos = v;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	rot = 0;
	speed = 200;
}

void Sprite::setTexture(string imagePath)
{
	texture = Texture(imagePath);
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	//glRotate and glScale

	//Rendering, full alpha
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);   glVertex2i(-texture.GetWidth()/2, -texture.GetHeight() / 2);
	glTexCoord2f(1, 0);   glVertex2i(texture.GetWidth()/2, -texture.GetHeight() / 2);
	glTexCoord2f(1, 1);   glVertex2i(texture.GetWidth()/2, texture.GetHeight() / 2);
	glTexCoord2f(0, 1);   glVertex2i(-texture.GetWidth() / 2, texture.GetHeight() / 2);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
}

void Sprite::EndRender() {
	glDisable(GL_TEXTURE_2D);
}

//Speed 

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

//Moving

void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{ //Using the class we made
	pos = pos + (v * Engine::GetDT());

}

//More movement

void Sprite::MoveLeft()
{
	pos = pos - Vector3((speed * Engine::GetDT()),0,0);
}

void Sprite::MoveRight()
{
	pos = pos + Vector3((speed * Engine::GetDT()), 0, 0);
}

void Sprite::MoveUp()
{
	pos = pos + Vector3(0,(speed * Engine::GetDT()),0);
}

void Sprite::MoveDown()
{
	pos = pos - Vector3(0, (speed * Engine::GetDT()), 0);
}

//Rotating

void Sprite::RotateTo(float x)
{
	rot = x;

}

void Sprite::RotateBy(float x)
{
	rot += (x * Engine::GetDT());

}

//Scaling

void Sprite::SetScale(float x)
{
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

//Accessors

Vector3* Sprite::GetPos()
{
	return &pos;
}

float* Sprite::GetRot()
{
	return &rot;
}

Vector3* Sprite::GetScale()
{
	return &scale;
}

Vector3* Sprite::GetSize()
{
	return &size;
}