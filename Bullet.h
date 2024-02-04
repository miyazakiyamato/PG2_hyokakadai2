#pragma once
#include "Object.h"
class Bullet:public Object{
public:
	Bullet();
	~Bullet();

	void Initalaze();
	void Update(char* keys, char* preKeys);
	void Draw(Vector2 textureSize, int gh);
};

