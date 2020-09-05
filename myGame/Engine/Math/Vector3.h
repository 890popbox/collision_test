#ifndef GAME_VECTOR3
#define GAME_VECTOR3

class Vector3
{ //Classic vec3 class, 3d space..
public:
	static float Dot(const Vector3 &a, const Vector3& b);
	static Vector3 Project(const Vector3 &a, const Vector3 &b);

	//Construct it, in many ways
	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y, float _z);

	//Assignment operators
	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator*(float _x);

	//Compare yes or no
	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	//Hold these..
	float x;
	float y;
	float z;

};



#endif