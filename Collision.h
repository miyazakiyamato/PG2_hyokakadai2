#pragma once
#include "Vector2.h"

class Collision final {
private:
	Collision() {}
	~Collision() {}
public:
	Collision(const Collision& obj) = delete;
	Collision& operator=(const Collision& obj) = delete;
	static Collision* GetInstance();
	static bool CircleCollision(Vector2 pos, Vector2 pos2, float radius, float radius2);
};

