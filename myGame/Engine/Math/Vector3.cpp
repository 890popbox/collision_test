#include "Vector3.h"
#include <math.h>

float Vector3::Dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y;
}

Vector3 Vector3::Project(const Vector3& a, const Vector3& b) {
	return Vector3( (Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.x,
	             	(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.y, 0);
}

Vector3::Vector3()
{ //Default Vec3
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& other)
{ //Make a vector with another one..
	x = other.x;
	y = other.y;
	z = other.z;
}

//Setting vec3 to one thing..
Vector3::Vector3(float _x)
{
	x = _x;
	y = _x;
	z = _x;
}

//Setting the 3 vec3 pos's
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	//Assignment and return..
	return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 ret;
	//Assignment..
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;

	return ret;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 ret;
	//Assignment..
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;

	return ret;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 ret;
	//Assignment..
	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;

	return ret;
}

Vector3 Vector3::operator*(float _x)
{
	Vector3 ret;
	//Assignment..
	ret.x = x * _x;
	ret.y = y * _x;
	ret.z = z * _x;

	return ret;
}


//Comparing stuff

bool Vector3::operator==(const Vector3& other)
{
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other)
{
	return !(*this == other);
}