#include "function.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

float Length(float x, float y) {
	return sqrtf(x * x + y * y);
}
float Normalize(float aPos, float length) {
	if (length != 0) {
		return aPos / length;
	}
	else {
		return aPos;
	}
}
bool LeftRight(Vector2 playerPos, Vector2 pos, Vector2 pos2) {
	float dot = (pos2.x - pos.x) * (playerPos.y - pos.y) - (pos2.y - pos.y) * (playerPos.x - pos.x);
	if (dot < 0) {
		return true;
	}
	return false;
}
float Clamp(float num, float min, float max) {
	if (num < min) {
		return min;
	}
	else if (num > max) {
		return max;
	}
	else {
		return num;
	}
}
void CTcount(int& ct, int time) {
	if (ct != 0) {
		ct++;
	}
	if (ct > time) {
		ct = 0;
	}
}

int Numset(int num, char* keys) {
	if (keys[DIK_0]) {
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		if (keys[i + 1]) {
			return i;
			break;
		}
	}
	return num;
}
int Numset(int num, char* keys, char* preKeys) {
	if (keys[DIK_0] && !preKeys[0]) {
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		if (keys[i + 1] && !preKeys[i + 1]) {
			return i;
			break;
		}
	}
	return num;
}

void PrintMap(int posX, int posY, int size, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color) {
	Novice::DrawQuad(
		posX * size + scsX, posY * size + scsY,
		posX * size + size + scsX, posY * size + scsY,
		posX * size + scsX, posY * size + size + scsY,
		posX * size + size + scsX, posY * size + size + scsY,
		tilenumX * size, tilenumY * size, size, size,
		texture, color);
}
void PrintQuad(int posX, int posY, int radiusX,int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color) {
	Novice::DrawQuad(
		posX - radiusX + scsX, posY - radiusY + scsY,
		posX + radiusX + scsX, posY - radiusY + scsY,
		posX - radiusX + scsX, posY + radiusY + scsY,
		posX + radiusX + scsX, posY + radiusY + scsY,
		tilenumX * radiusX * 2, tilenumY * radiusY * 2, radiusX * 2, radiusY * 2,
		texture, color);
}
void Printrotate(Vertex world, int radiusX, int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color){
	Novice::DrawQuad(
		(int)world.leftTop.x + scsX, (int)world.leftTop.y + scsY,
		(int)world.rightTop.x + scsX, (int)world.rightTop.y + scsY,
		(int)world.leftBottom.x + scsX, (int)world.leftBottom.y + scsY,
		(int)world.rightBottom.x + scsX, (int)world.rightBottom.y + scsY,
		tilenumX * radiusX * 2, tilenumY * radiusY * 2, radiusX * 2, radiusY * 2,
		texture, color);
}

float GetPI() { return (float)M_PI; }

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	Matrix3x3 m;
	m.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0];
	m.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1];
	m.m[0][2] = matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2];
	m.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0];
	m.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1];
	m.m[1][2] = matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2];
	m.m[2][0] = matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0];
	m.m[2][1] = matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1];
	m.m[2][2] = matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2];
	return m;
}
Matrix3x3 MakeScaleMatrix(Vector2 scale) {
	Matrix3x3 m;
	m.m[0][0] = scale.x;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = scale.y;
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	return m;
}
Matrix3x3 MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 m;
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[2][0] = translate.x;
	m.m[2][1] = translate.y;
	m.m[2][2] = 1;
	return m;
}
Vector2 TransForm(Vector2 v, Matrix3x3 matrix) {
	Vector2 resalt;
	resalt.x = v.x * matrix.m[0][0] + v.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	resalt.y = v.x * matrix.m[0][1] + v.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = v.x * matrix.m[0][2] + v.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	resalt.x /= w;
	resalt.y /= w;
	return resalt;
}
Matrix3x3 MakeRotateMatrix(float theta) {
	Matrix3x3 m;
	m.m[0][0] = cosf(theta);
	m.m[0][1] = sinf(theta);
	m.m[0][2] = 0;
	m.m[1][0] = -sinf(theta);
	m.m[1][1] = cosf(theta);
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	return m;
}
Vector2 MakeWorldMatrix(Vector2 pos,Vector2 size, float theta, Vector2 translate) {
	Matrix3x3 m;
	Vector2 v = pos;
	m = Multiply(Multiply(MakeScaleMatrix(size), MakeRotateMatrix(theta)), MakeTranslateMatrix(translate));
	v = TransForm(v, m);
	return v;
}
Vertex MakeVertex(Vertex n,Vector2 size, float theta, Vector2 translate) {
	Vertex world;
	world.leftTop = MakeWorldMatrix(n.leftTop, size, theta, translate);
	world.rightTop = MakeWorldMatrix(n.rightTop, size, theta, translate);
	world.leftBottom = MakeWorldMatrix(n.leftBottom, size, theta, translate);
	world.rightBottom = MakeWorldMatrix(n.rightBottom, size, theta, translate);
	return world;
}
