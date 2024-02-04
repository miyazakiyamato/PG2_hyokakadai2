#pragma once
#include "Object.h"
class Enemy:public Object{
protected:
	int count_{};
public:
	virtual ~Enemy();

	virtual void Initalaze() = 0;
	virtual void Update() = 0;
	virtual void Draw(Vector2 textureSize, int gh) = 0;
};

