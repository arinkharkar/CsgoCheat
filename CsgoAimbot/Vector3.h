#pragma once
class  Vector3 {
public:
	float x, y, z;
	Vector3();
	Vector3(float _x, float _y, float _z);
	float GetLength();
};

class  vector3 {
public:
	float x, y, z;
	vector3() {
		x = y = z = 0;
	}
	vector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	float GetLength() {
		return 0;
	}
};

Vector3 operator-(Vector3 vec, Vector3 other);