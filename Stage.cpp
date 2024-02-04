#include "Stage.h"

Stage::Stage(){
	Initalaze();
}

Stage::~Stage(){

}

void Stage::Initalaze(){
	player = new Player();
	player->SetIsAlive(true);
	for (int i = 0; i < 2; i++) {
		enemy[i] = new SmallEnemy();
		enemy[i]->SetPos({100 + 500 * float(i),100});
		enemy[i]->SetIsAlive(true);
	}
	isClear_ = false;
}

void Stage::Update(char* keys, char* preKeys){
	player->Update(keys, preKeys);
	for (int i = 0; i < 2; i++) {
		enemy[i]->Update();
	}
	for (int i = 0; i < 2; i++) {
		if (Collision::CircleCollision(player->GetPos(),enemy[i]->GetPos(),player->GetRadiusX(),enemy[i]->GetRadiusX())) {
			enemy[i]->SetIsAlive(false);
		}
		for (int j = 0; j < 10; j++) {
			if (Collision::CircleCollision(player->bullet[j]->GetPos(), enemy[i]->GetPos(), player->bullet[j]->GetRadiusX(), enemy[i]->GetRadiusX())) {
				enemy[i]->SetIsAlive(false);
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		if (enemy[i]->GetIsAlive()) {
			break;
		}
		if (i == 1) {
			isClear_ = true;
		}
	}
	if (isClear_) {
		isScene_ = true;
	}
}

void Stage::Draw(){
	Novice::ScreenPrintf(0, 0, "stage");
	Novice::DrawSprite(0, 0, BGgh_, 1.f, 1.f, 0.0f, 0xffffffff);
	Novice::DrawSprite(680, 0, BGgh2_, 1.f, 1.f, 0.0f, 0xffffffff);
	player->Draw({0,0},playergh_);
	for (int i = 0; i < 2; i++) {
		enemy[i]->Draw({0,0},enemygh_);
	}
	if (isClear_) {
		Novice::ScreenPrintf(0, 100, "Clear");
	}
}

