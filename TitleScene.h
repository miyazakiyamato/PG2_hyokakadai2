#pragma once
#include "Scene.h"
class TitleScene:public Scene {
private:
	
	int gh_ = Novice::LoadTexture("./image/title.png");
public:
	
	TitleScene();
	~TitleScene();

	void Initalaze();
	void Update(char* keys, char* preKeys);
	void Draw();
};

