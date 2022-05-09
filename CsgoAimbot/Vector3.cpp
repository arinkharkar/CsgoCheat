#include <math.h>
#include "Vector3.h"


	
Vector3::Vector3() {
	x = 0.f;
	y = 0.f;
	z = 0.f;
}
Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

/* This makes sense if you look at a 2d vector, its just the pythagorean theorem */
float Vector3::GetLength() {
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

Vector3 operator-(Vector3 vec, Vector3 other) {
	return Vector3(vec.x - other.x, vec.y - other.y, vec.z - other.z);
}