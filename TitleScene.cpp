#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initalaze()
{
}

void TitleScene::Update(char* keys, char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isScene_ = true;
	}
}

void TitleScene::Draw(){
	Novice::ScreenPrintf(0, 0, "title");
	Novice::DrawSprite(0, 0, gh_, 1.f, 1.f, 0.0f, 0xffffffff);
}
