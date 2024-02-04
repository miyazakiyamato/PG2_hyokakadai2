#include "ResultScene.h"

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene(){

}

void ResultScene::Initalaze()
{
}

void ResultScene::Update(char* keys, char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isScene_ = true;
	}
}

void ResultScene::Draw(){
	Novice::ScreenPrintf(0, 0, "result");
	Novice::DrawSprite(0, 0, gh_, 1.f, 1.f, 0.0f, 0xffffffff);
}
