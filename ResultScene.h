#pragma once
#include "Scene.h"
class ResultScene :public Scene {
private:
	int gh_ = Novice::LoadTexture("./image/clear.png");

public:
	
	ResultScene();
	~ResultScene();

	void Initalaze();
	void Update(char* keys, char* preKeys);
	void Draw();
};

