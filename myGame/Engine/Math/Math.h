#ifndef GAME_MATH
#define GAME_MATH

#include "Vector3.h"
#include <vector>

using namespace std;
#define PI 3.14159

namespace Math
{
	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);
	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot);
	float Min(vector<float> x);
	float Max(vector<float> x);
}

#endif
