#pragma once
#include "Object.h"
#include "Bullet.h"
class Player:public Object{
private:
	int coolTime;
	int bulletgh_ = Novice::LoadTexture("./image/tama.png");
public:
	Bullet* bullet[10];

	Player();
	~Player();

	void Initalaze();
	void Update(char* keys,char* preKeys);
	void Draw(Vector2 textureSize, int gh);
};

