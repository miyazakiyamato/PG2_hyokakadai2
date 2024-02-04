#pragma once
#include "Enemy.h"
class SmallEnemy:public Enemy{
private:
	float theta;
public:
	SmallEnemy();
	~SmallEnemy();

	void Initalaze();
	void Update();
	void Draw(Vector2 textureSize, int gh);
};

