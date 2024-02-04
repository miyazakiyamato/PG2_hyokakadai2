#pragma once
#include "Scene.h"
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
#include "SmallEnemy.h"

class Stage:public Scene{
private:
	Player* player;
	Enemy* enemy[2];
	bool isClear_{};

	int playergh_ = Novice::LoadTexture("./image/player.png");
	int enemygh_ = Novice::LoadTexture("./image/enemy.png");
	int BGgh_ = Novice::LoadTexture("./image/haikei.png");
	int BGgh2_ = Novice::LoadTexture("./image/haikei2.png");
public:
	
	Stage();
	~Stage();

	void Initalaze();
	void Update(char* keys, char* preKeys);
	void Draw();

};

