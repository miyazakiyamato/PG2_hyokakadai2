#pragma once
#include "Struct.h"
float Length(float x, float y);
float Normalize(float aPos, float length);
bool LeftRight(Vector2 playerPos, Vector2 pos, Vector2 pos2);
float Clamp(float num, float min, float max);
void CTcount(int& ct, int time);
int Numset(int num, char* keys);
int Numset(int num, char* keys, char* preKeys);
void PrintMap(int posX, int posY, int size, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color);
void PrintQuad(int posX, int posY, int radiusX,int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color);
void Printrotate(Vertex world, int radiusX, int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color);
float GetPI();
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);
Matrix3x3 MakeScaleMatrix(Vector2 scale);
Matrix3x3 MakeTranslateMatrix(Vector2 translate);
Vector2 TransForm(Vector2 v, Matrix3x3 matrix);
Matrix3x3 MakeRotateMatrix(float theta);
Vector2 MakeWorldMatrix(Vector2 pos, Vector2 size, float theta, Vector2 translate);
Vertex MakeVertex(Vertex n, Vector2 size, float theta, Vector2 translate);
